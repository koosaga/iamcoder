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

lint val(int x, int y){
	return 1ll * (y - x) * t[y] + v[x];
}

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
		int s = max(0, i-d), e = i;
		while(s != e){
			int m = (s+e)/2;
			if(val(m, i) > val(m+1, i)){
				e = m;
			} 
			else s = m+1;
		}
		ret = max(ret, val(s, i));
	}
	printf("%lld\n",ret);
}