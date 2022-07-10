#include <iostream>
<<<<<<< HEAD

using namespace std;

char arr[3002][3002];
int dp[3][3002][3002];

=======
#define INF 1000000007

using namespace std;

char arr[3001][3001];
unsigned long long int dp[3][3001][3001];
>>>>>>> 112d840399aa11f6d1cb7a57e6c5a4ffffa2dac8

int N, M;

int main(void) {
	cin >> N >> M;
<<<<<<< HEAD
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'E') dp[0][i][j] = 1;
			else if (arr[i][j] == 'S') dp[1][i][j] = 1;
			else if (arr[i][j] == 'M') dp[2][i][j] = 1;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[0][i][j] += dp[0][i - 1][j] + dp[0][i][j - 1] - dp[0][i - 1][j - 1];
			dp[1][i][j] += dp[1][i - 1][j] + dp[1][i][j - 1] - dp[1][i - 1][j - 1];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[2][i][j] = dp[0][i][j] * dp[1][i][j];
		}
	}

	long long int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == 'M') ans += dp[2][i][j] - dp[2][i - 1][j - 1];
		}
	}
	cout << ans;
=======
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'E') dp[0][i][j] = 1;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'E') {
				if (i - 1 >= 0 && arr[i - 1][j] == 'E') dp[0][i][j] += dp[0][i - 1][j] % INF;
				if (j - 1 >= 0 && arr[i][j - 1] == 'E') dp[0][i][j] += dp[0][i][j - 1] % INF;
				if (i - 1 >= 0 && j - 1 >= 0 && arr[i - 1][j - 1] == 'E') dp[0][i][j] += dp[0][i - 1][j - 1] % INF;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'S') {
				if (i - 1 >= 0 && arr[i - 1][j] == 'S') dp[1][i][j] += dp[1][i - 1][j] % INF;
				if (j - 1 >= 0 && arr[i][j - 1] == 'S') dp[1][i][j] += dp[1][i][j - 1] % INF;
				if (i - 1 >= 0 && j - 1 >= 0 && arr[i - 1][j - 1] == 'S') dp[1][i][j] += dp[1][i - 1][j - 1] % INF;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'M') {
				if (i - 1 >= 0 && arr[i - 1][j] == 'M') dp[2][i][j] += dp[2][i - 1][j] % INF;
				if (j - 1 >= 0 && arr[i][j - 1] == 'M') dp[2][i][j] += dp[2][i][j - 1] % INF;
				if (i - 1 >= 0 && j - 1 >= 0 && arr[i - 1][j - 1] == 'M') dp[2][i][j] += dp[2][i - 1][j - 1] % INF;
			}
		}
	}

	unsigned long long int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'M') ans += dp[2][i][j] % 1000000007;
		}
	}

	cout << ans % 1000000007;
>>>>>>> 112d840399aa11f6d1cb7a57e6c5a4ffffa2dac8

	return 0;
}