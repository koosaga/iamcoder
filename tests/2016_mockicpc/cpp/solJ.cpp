#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

struct intv{
    int s, x, e, idx;
}a[1000005];

int n, m;
int l[1000005], r[1000005];
int ret[1000005];
bool vis[1000005];

struct seg1{
    pi tree[2100000];
    int lim;
    void init(int n){
        for(lim = 1; lim <= n; lim <<= 1);
        fill(tree, tree + 2100000, pi(-2e9, -1));
        for(int i=0; i<n; i++){
            tree[i + lim] = pi(a[i].e, i);
        }
        for(int i=lim-1; i; i--){
            tree[i] = max(tree[2*i], tree[2*i+1]);
        }
    }
    void add(int x, int v){
        tree[x + lim] = pi(v, x);
        x += lim;
        while(x > 1){
            x >>= 1;
            tree[x] = max(tree[2*x], tree[2*x+1]);
        }
    }
    pi query(int s, int e){
        pi ret(-2e9, -1);
        s += lim;
        e += lim;
        while(s < e){
            if(s%2 == 1) ret = max(ret, tree[s++]);
            if(e%2 == 0) ret = max(ret, tree[e--]);
            s >>= 1;
            e >>= 1;
        }
        if(s == e) ret = max(ret, tree[s]);
        return ret;
    }
}seg1;

struct seg2{
    pi tree[2100000];
    int lim;
    void init(int n){
        for(lim = 1; lim <= n; lim <<= 1);
        fill(tree, tree + 2100000, pi(2e9, -1));
        for(int i=0; i<n; i++){
            tree[i + lim] = pi(a[i].s, i);
        }
        for(int i=lim-1; i; i--){
            tree[i] = min(tree[2*i], tree[2*i+1]);
        }
    }
    void add(int x, int v){
        tree[x + lim] = pi(v, x);
        x += lim;
        while(x > 1){
            x >>= 1;
            tree[x] = min(tree[2*x], tree[2*x+1]);
        }
    }
    pi query(int s, int e){
        pi ret(2e9, -1);
        s += lim;
        e += lim;
        while(s < e){
            if(s%2 == 1) ret = min(ret, tree[s++]);
            if(e%2 == 0) ret = min(ret, tree[e--]);
            s >>= 1;
            e >>= 1;
        }
        if(s == e) ret = min(ret, tree[s]);
        return ret;
    }
}seg2;

bool cmp1(intv a, intv b){ return a.s < b.s; }
bool cmp2(intv a, intv b){ return a.e < b.e; }

void dfs1(int x, int v){
    vis[x] = 1;
    l[a[x].idx] = v;
    int p = lower_bound(a, a+n, (intv){a[x].x+1, 0, 0, 0}, cmp1) - a;
    while(1){
        auto t = seg1.query(0, p-1);
        if(t.first < a[x].x) break;
        seg1.add(t.second, -2e9);
        dfs1(t.second, v);
    }
}

void dfs2(int x, int v){
    vis[x] = 1;
    r[a[x].idx] = v;
    int p = lower_bound(a, a+n, (intv){0, 0, a[x].x, 0}, cmp2) - a;
    while(1){
        auto t = seg2.query(p, n-1);
        if(t.first > a[x].x) break;
        seg2.add(t.second, 2e9);
        dfs2(t.second, v);
    }
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++){
        scanf("%d %d %d",&a[i].x,&a[i].s,&a[i].e);
        a[i].s = a[i].x - a[i].s;
        a[i].e = a[i].x + a[i].e;
        a[i].idx = i;
    }
    sort(a, a+n, cmp1);
    seg1.init(n);
    memset(vis, 0, sizeof(vis));
    for(int i=0; i<n; i++){
        if(!vis[i]) dfs1(i, a[i].s);    
    }
    sort(a, a+n, cmp2);
    seg2.init(n);
    memset(vis, 0, sizeof(vis));
    for(int i=n-1; i>=0; i--){
        if(!vis[i]) dfs2(i, a[i].e);
    }
    vector<pi> v, w;
    for(int i=0; i<n; i++){
        v.push_back({l[i], 1});
        v.push_back({r[i]+1, -1});
    }
    sort(v.begin(), v.end());
    for(int i=0; i<m; i++){
        int x;
        scanf("%d",&x);
        w.push_back({x, i});
    }
    sort(w.begin(), w.end());
    int p = 0;
    int cnt = 0;
    for(int i=0; i<m; i++){
        while(p < v.size() && v[p].first <= w[i].first){
            cnt += v[p].second;
            p++;
        }
        ret[w[i].second] = cnt;
    }
    for(int i=0; i<m; i++){
        printf("%d\n", ret[i]);
    }
}
