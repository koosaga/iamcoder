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

map<int,int> mp;
int n;

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		mp[s]++;
		mp[e]--;
	}
	int prev = 0, ret = 1;
	for(auto &i : mp){
		prev += i.second;
		i.second = prev;
		ret = max(ret, prev);
	}
	printf("%d",ret);
}