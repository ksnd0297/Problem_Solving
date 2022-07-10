#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int A[11];
int map[11][11];


int main(void)
{
	int N; cin >> N;
	for (int i = 0; i < N; i++) A[i] = i;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	int ans = INT_MAX;
	do {
		bool flag = false; int min = 0;
		for (int i = 0; !flag && i < N - 1; i++) {
			if (map[A[i]][A[i + 1]] == 0) flag = true;
			min += map[A[i]][A[i + 1]];
		}
		if (map[A[N-1]][A[0]] == 0) flag = true;
		if (flag) continue;
		min += map[A[N-1]][A[0]];
		if (ans > min) ans = min;
	} while (next_permutation(A + 1, A + N));
	cout << ans;
	return 0;
}