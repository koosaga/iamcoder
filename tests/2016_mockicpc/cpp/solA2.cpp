#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

static char _buffer[1 << 19];
static int _currentChar = 0;
static int _charsNumber = 0;

static inline int _read() {
    if (_charsNumber < 0) {
        exit(1);
    }
    if (!_charsNumber || _currentChar == _charsNumber) {
        _charsNumber = (int)fread(_buffer, sizeof(_buffer[0]), sizeof(_buffer), stdin);
        _currentChar = 0;
    }
    if (_charsNumber <= 0) {
        return -1;
    }
    return _buffer[_currentChar++];
}

static inline int _readInt() {
    int c, x, s;
    c = _read();
    while (c <= 32) c = _read();
    x = 0;
    s = 1;
    if (c == '-') {
        s = -1;
        c = _read();
    }
    while (c > 32) {
        x *= 10;
        x += c - '0';
        c = _read();
    }
    if (s < 0) x = -x;
    return x;
}
struct tup{
    int x, y, v;
    bool operator<(const tup &t)const{
        return v < t.v;
    }
};

int n, m, c[1005][1005];

struct bit{
    lint tree[1005][1005];
    void init(){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                tree[i][j] = -1e18;
            }
        }
    }
    void add(int x, int y, lint v){
        for(int i=x; i<=n; i+=i&-i){
            for(int j=y; j<=m; j+=j&-j){
                tree[i][j] = max(tree[i][j], v);
            }
        }
    }
    lint query(int x, int y){
        lint ret = -1e18;
        for(int i=x; i; i-=i&-i){
            for(int j=y; j; j-=j&-j){
                ret = max(ret, tree[i][j]);
            }
        }
        return ret;
    }   
}seg1, seg2, seg3, seg4;

vector<tup> v;
lint dp[1000005];

int main(){
    n = _readInt();
    m = _readInt();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int t = _readInt(); 
            if(t != 0){
                v.push_back((tup){i, j, t});
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            c[i][j] = _readInt();
        }
    }
    seg1.init();
    seg2.init();
    seg3.init();
    seg4.init();
    lint ret = 0;
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); ){
        int e = i;
        while(e < v.size() && v[e].v == v[i].v) e++;
        vector<lint> aux;
        for(int j=i; j<e; j++){
            dp[j] = max(dp[j], seg1.query(v[j].x, v[j].y) + v[j].x + v[j].y);
            dp[j] = max(dp[j], seg2.query(n + 1 - v[j].x, m + 1 - v[j].y) - v[j].x - v[j].y);
            dp[j] = max(dp[j], seg3.query(n + 1 - v[j].x, v[j].y) - v[j].x + v[j].y);
            dp[j] = max(dp[j], seg4.query(v[j].x, m + 1 - v[j].y) + v[j].x - v[j].y);
            dp[j] += c[v[j].x][v[j].y];
            ret = max(ret, dp[j]);
        }
        for(int j=i; j<e; j++){
            seg1.add(v[j].x, v[j].y, dp[j] - v[j].x - v[j].y);
            seg2.add(n + 1 - v[j].x, m + 1 - v[j].y, dp[j] + v[j].x + v[j].y);
            seg3.add(n + 1 - v[j].x, v[j].y, dp[j] + v[j].x - v[j].y);
            seg4.add(v[j].x, m + 1 - v[j].y, dp[j] - v[j].x + v[j].y);
        }
        i = e;
    }
    cout << ret;
}
