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
#include "tokens.h"
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

// build : g++ -o tokens koistudy.cpp tokens.cpp

int get_pick(int strategy, int SQRT, int N, int A[40][40], set<int> &s){
	if(strategy == 1){ // example strategy
		return *s.begin();
	}
	if(strategy == 2){ // random strategy
		int min_val = 0, min_pos = 1e9;
		for(set<int> ::iterator it = s.begin(); it != s.end(); it++){
			int i = *it;
			if(min_pos > i % SQRT){
				min_pos = i % SQRT;
				min_val = i;
			}
		}
		return min_val;
	}
	if(strategy == 3){ // optimal strategy
		int min_val = 0, min_pos = -1e9;
		for(set<int> ::iterator it = s.begin(); it != s.end(); it++){
			int tis = 0;
			for(int i=0; i<N; i++){
				tis += A[*it][i] + A[i][*it];
			}
			if(min_pos < tis){
				min_pos = tis;
				min_val = *it;
			}
		}
		return min_val;
	}
	return -1;
}

int getBest(set<int> &s, int n, int A[40][40]){
	if(s.empty()) return -1;
	int min_val = 0, min_pos = -1e9;
	for(set<int> ::iterator it = s.begin(); it != s.end(); it++){
		int tis = 0;
		for(int i=0; i<n; i++){
			tis += A[*it][i] + A[i][*it];
		}
		if(min_pos < tis){
			min_pos = tis;
			min_val = *it;
		}
	}
	return min_val;
}

int emulate(int N, int strategy, int SQRT, int A[40][40]){
	set<int> s;
	vector<int> JH, SW;
	for(int i=0; i<N; i++) s.insert(i);
	while(!s.empty()){
		int jaehyun = get_pick(strategy, SQRT, N, A, s);
		JH.push_back(jaehyun);
		s.erase(jaehyun);
		int seungwon = getBest(s, N, A);
		if(seungwon == -1) continue;
		else{
			s.erase(seungwon);
			SW.push_back(seungwon);
		}
	}
	int ret = 0;
	for(int i=0; i<JH.size(); i++){
		for(int j=0; j<JH.size(); j++){
			ret -= A[JH[i]][JH[j]];
		}
	}
	for(int i=0; i<SW.size(); i++){
		for(int j=0; j<SW.size(); j++){
			ret += A[SW[i]][SW[j]];
		}
	}
	return ret;
}

int main(){
	int N, strategy;
	int A[40][40] = {};
	int ret = 0, SQRT = 0;

	set<int> s;
	vector<int> JH, SW;

	scanf("%d %d",&N, &strategy);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d",&A[i][j]);
		}
		s.insert(i);
	}

	int b[40][40];
	memcpy(b, A, sizeof(b));
	init(N, b);

	for(; SQRT*SQRT <= N; SQRT++);
	SQRT--;

	int result = emulate(N, strategy, SQRT, A);

	while(!s.empty()){
		int jaehyun = get_pick(strategy, SQRT, N, A, s);
		JH.push_back(jaehyun);
		s.erase(jaehyun);
		int seungwon = play(jaehyun);
		if(seungwon == -1) continue;
		else{
			if(s.find(seungwon) == s.end()){
				puts("Wrong Answer");
				return 0;
			}
			s.erase(seungwon);
			SW.push_back(seungwon);
		}
	}
	for(int i=0; i<JH.size(); i++){
		for(int j=0; j<JH.size(); j++){
			ret -= A[JH[i]][JH[j]];
		}
	}
	for(int i=0; i<SW.size(); i++){
		for(int j=0; j<SW.size(); j++){
			ret += A[SW[i]][SW[j]];
		}
	}
	if(result != ret){
		puts("Wrong Answer");
	}
	else{
		puts("Accepted");
	}
}