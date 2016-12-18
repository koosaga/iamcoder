#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int main(){
    int t, cnt;
    cin >> t;
    while(t--){
        int n;
        lint a[505];
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        if(n <= 4) puts("YES");
        else{
            lint v[4];
            v[3] = -1 * a[1] + 3 * a[2] - 3 * a[3] + a[4];
            v[2] = 9 * a[1] - 24 * a[2] + 21 * a[3] - 6 * a[4];
            v[1] = -26 * a[1] + 57 * a[2] - 42 * a[3] + 11 * a[4];
            v[0] = 24 * a[1] - 36 * a[2] + 24 * a[3] - 6 * a[4];
            bool bad = 0;
            for(int i=5; i<=n; i++){
                lint eval = v[0] + v[1] * i + v[2] * i * i + v[3] * i * i * i;
                if(eval != a[i] * 6){
                    bad = 1;
                    break;
                }
            }
            puts(bad ? "NO" : "YES");
        }
    }
}
