#include "tokens.h"
#include <cstring>
#include <set>
using namespace std;

int a[40][40], n;
set<int> s;

void init(int N, int A[40][40]){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			a[i][j] = A[i][j];
		}
		s.insert(i);
	}
	n = N;
}


int play(int X){
	s.erase(X);
	if(s.empty()) return -1;
	int min_val = 0, min_pos = -1e9;
	for(set<int> ::iterator it = s.begin(); it != s.end(); it++){
		int tis = 0;
		for(int i=0; i<n; i++){
			tis += a[*it][i] + a[i][*it];
		}
		if(min_pos < tis){
			min_pos = tis;
			min_val = *it;
		}
	}
	s.erase(min_val);
	return min_val;
}