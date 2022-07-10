#include <iostream>

using namespace std;

int arr[501][501];
long long int dp[501][501];

int main(void)
{
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	dp[0][0] = arr[0][0];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (dp[i + 1][j] < dp[i][j] + arr[i + 1][j]) dp[i + 1][j] = dp[i][j] + arr[i + 1][j];
			if (dp[i + 1][j + 1] < dp[i][j] + arr[i + 1][j + 1]) dp[i + 1][j + 1] = dp[i][j] + arr[i + 1][j + 1];
		}
	}

	long long int max = 0;
	for (int i = 0; i < N; i++) {
		if (max < dp[N - 1][i]) max = dp[N - 1][i];
	}
	cout << max;
	return 0;
}