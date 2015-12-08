#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n, d;
int t[100005], v[100005];

int main(){
    scanf("%d %d",&n,&d);
    for(int i=0; i<n; i++){
        scanf("%d",&t[i]);
    }
    for(int i=0; i<n; i++){
        scanf("%d",&v[i]);
    }
    lint ret = 0;
    for(int i=0; i<n; i++){
        for(int j=max(i-d, 0); j<=min(max(i-d, 0) + 20000, i) ; j++){
            ret = max(ret, 1ll * (i-j) * t[i] + v[j]);
        }
    }
    printf("%lld\n",ret);
}