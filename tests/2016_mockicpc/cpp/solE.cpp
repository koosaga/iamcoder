#include <bits/stdc++.h>
using namespace std;

int chk[10005];
int n, q;

int main(){
    cin >> n >> q;
    while(q--){
        int s, p;
        cin >> s >> p;
        for(int j=s; j<=n; j+=p) chk[j] = 1;
    }
    cout << count(chk+1, chk+n+1, 0) << endl;
}