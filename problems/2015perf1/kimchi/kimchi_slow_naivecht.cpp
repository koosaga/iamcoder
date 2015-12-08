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
	deque<pi> dq;
	bool bad(pi a, pi b, pi c){
		return 1ll * (a.second - b.second) * (c.first - b.first) > 1ll * (b.second - c.second) * (b.first - a.first);
	}
	void add(int a, int b){
		while(dq.size() >= 2 && bad(dq[dq.size() - 2], dq.back(), pi(a, b))){
			dq.pop_back();
		}
		dq.push_back(pi(a, b));
	}
	lint hamsu(pi t, int x){ 
		return 1ll * t.first * x + t.second;
	}
	lint query(int x){
		lint ret = -1e18;
		for(int i=0; i<dq.size(); i++){
			ret = max(ret, hamsu(dq[i], x));
		}
		return ret;
	}
};

struct seg{
	cht tree[265000];
	int lim;
	void init(int n){
		for(lim = 1; lim <= n; lim <<= 1);
	}
	void add(int pos, pi a){
		pos += lim;
		while(pos){
			tree[pos].add(a.first, a.second);
			pos >>= 1;
		}
	}
	lint query(int s, int e, int x){
		s += lim;
		e += lim;
		lint ret = -1e18;
		while(s < e){
			if(s%2 == 1) ret = max(ret, tree[s++].query(x));
			if(e%2 == 0) ret = max(ret, tree[e--].query(x));
			s >>= 1;
			e >>= 1;
		}
		if(s == e) ret = max(ret, tree[s].query(x));
		return ret;
	}
}seg;

int main(){
	scanf("%d %d",&n,&d);
	for(int i=0; i<n; i++){
		scanf("%d",&t[i]);
	}
	for(int i=0; i<n; i++){
		scanf("%d",&v[i]);
	}
	lint ret = 0;
	seg.init(n);
	for(int i=0; i<n; i++){
		seg.add(i, pi(i, v[i]));
		ret = max(ret, 1ll * i * t[i] + seg.query(max(i-d,0), i, -t[i]));
	}
	printf("%lld\n",ret);
}