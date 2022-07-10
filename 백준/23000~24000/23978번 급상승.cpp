#include <iostream>

using namespace std;

char arr[3001][3001];
int dp[3001][3001][2];

int N, M;

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'S') {
				if (i - 1 >= 0 && arr[i - 1][j] == 'E') dp[i][j][0]++;
				if (j - 1 >= 0 && arr[i][j - 1] == 'E') dp[i][j][0]++;
				if (i - 1 >= 0 && j - 1 >= 0 && arr[i - 1][j - 1] == 'E') dp[i][j][0]++;
			}
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'M') {
				if (i - 1 >= 0 && arr[i - 1][j] == 'S') dp[i][j][1] += dp[i - 1][j][0] % 1000000007;
				if (j - 1 >= 0 && arr[i][j - 1] == 'S') dp[i][j][1] += dp[i][j-1][0] % 1000000007;
				if (i - 1 >= 0 && j - 1 >= 0 && arr[i - 1][j - 1] == 'S') dp[i][j][1] += dp[i - 1][j - 1][0] % 1000000007;
			}
		}
	}

	long long int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (dp[i][j][1] != 0) ans += dp[i][j][1];
		}
	}
	cout << ans;

	return 0;
}