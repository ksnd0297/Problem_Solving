#include <iostream>
#include <algorithm>
using namespace std;

int stair[301];
int dp[2][301];

int N;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> stair[i];

	dp[0][0] = stair[0];
	dp[0][1] = stair[1];
	dp[1][1] = dp[0][0] + stair[1];

	for (int i = 2; i <= N; i++) {
		dp[0][i] = max(dp[0][i - 2], dp[1][i - 2]) + stair[i];
		dp[1][i] = dp[0][i - 1] + stair[i];
	}

	cout << max({ dp[0][N - 2], dp[0][N - 1], dp[1][N - 1] }) + stair[N];

	return 0;
}