#include "tokens.h"
#include <set>
#include <vector>
#include <cstdio>
using namespace std;

set<int> s;
vector<int> JH, SW;

int main(){
	int n, a[40][40] = {};
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d",&a[i][j]);
			s.insert(i);
		}
	}
	init(n, a);
	while(!s.empty()){
		int jaehyun;
		scanf("%d",&jaehyun);
		if(s.find(jaehyun) == s.end()){
			// This will not happen in actual grading stage.
			puts("Error : Wrong Pick from Jaehyun");
			return 0;
		}
		JH.push_back(jaehyun);

		int seungwon = play(jaehyun);
		if(seungwon == -1) continue;
		else{
			if(s.find(seungwon) == s.end()){
				// If this happens in grading stage, you will get Wrong Answer verdict.
				puts("Error : Wrong Pick from Seungwon");
				return 0;
			}
			s.erase(seungwon);
			SW.push_back(seungwon);
		}
	}
	int ret = 0;
	for(int i=0; i<JH.size(); i++){
		for(int j=0; j<JH.size(); j++){
			ret -= a[JH[i]][JH[j]];
		}
	}
	for(int i=0; i<SW.size(); i++){
		for(int j=0; j<SW.size(); j++){
			ret += a[SW[i]][SW[j]];
		}
	}
	printf("%d",ret);
	return 0;
}