#include "tokens.h"

int a[40][40], n;

void init(int N, int A[40][40]){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			a[i][j] = A[i][j]; // no memcpy, please.
		}
	}
	n = N;
}

int play(int X){
	return -1;
}