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

struct cht{
	int pa[100005], pb[100005], p, sz;
	void add(int a, int b){
		pa[sz] = a;
		pb[sz] = b;
		while(sz >= p+2 && 1ll * (pb[sz-2] - pb[sz-1]) * (pa[sz] - pa[sz-1]) > 1ll * (pb[sz-1] - pb[sz]) * (pa[sz-1] - pa[sz-2])){
			pa[sz-1] = pa[sz];
			pb[sz-1] = pb[sz];
			sz--;
		}
		sz++;
	}
	lint query(int x, int lim){
		while(p + 1 < sz && 1ll * pa[p] * x + pb[p] <= 1ll * x * pa[p+1] + pb[p+1]) p++;
		while(p + 1 < sz && pa[p] < lim) p++;
		return 1ll * pa[p] * x + pb[p];
	}
}cht;

int main(){
	scanf("%d %d",&n,&d);
	for(int i=0; i<n; i++){
		scanf("%d",&t[i]);
	}
	for(int i=0; i<n; i++){
		scanf("%d",&v[i]);
	}
	lint ret = *max_element(v, v + n);
	for(int i=0; i<n; i++){
		ret = max(ret, 1ll * i * t[i] + cht.query(-t[i], i - d));
		cht.add(i, v[i]);
	}
	printf("%lld\n",ret);
}