#include <bits/stdc++.h>
using namespace std;

const int MX = 10050;

int get_LCS(char* D, int X, char* E, int Y)
{
	int* T[2] = { new int[Y+1], new int[Y+1] };
	for (int i = 0; i <= Y; i++) T[0][i] = T[1][i] = 0;
	int s = 0, e = 1;
	for (int i = 1; i <= X; i++){
		for (int j = 1; j <= Y; j++){
			T[e][j] = max(T[s][j], T[e][j - 1]);
			if (D[i] == E[j]) T[e][j] = max(T[e][j], T[s][j - 1] + 1);
		}
		swap(s, e);
	}
	return T[s][Y];
}

int n, c, ret;
char A[MX], B[MX];

int main(int argc, char **argv){
	FILE *in = fopen(argv[1],"r");
	FILE *sol = fopen(argv[2],"r");
	FILE *out = fopen(argv[3],"r");
	// input
	fscanf(in, "%d %s", &n, A+1);
	// output sane check
	assert(fscanf(out, "%d\n", &c) == 1);
	fgets(B+1, MX-2, out);
	for(int i=1; i<=n; i++){
		assert(B[i] == 'A' || B[i] == 'C' || B[i] == 'G' || B[i] == 'T');
	}
	assert(B[n+1] != 'A' && B[n+1] != 'C' && B[n+1] != 'G' && B[n+1] != 'T');
	B[n+1] = 0;
	A[n+1] = 0;
	// solution output
	fscanf(sol, "%d", &ret);
	assert(c == ret);
	assert(get_LCS(A, n, B, n) == c);
}
