#include <iostream>

using namespace std;

int dp[1516][3];

int main(void) {
	dp[0][2] = 1;
	dp[1][0] = 1; dp[1][1] = 1;

	for (int i = 2; i <= 1515; i++) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % 1000000007;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 1000000007;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 1000000007;
	}
	int N; cin >> N;
	cout << dp[N-1][0];
	return 0;
}