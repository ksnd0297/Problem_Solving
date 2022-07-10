#include <iostream>
#include <cstring>

using namespace std;

int N;
long long int dp[101];
const int MOD = 1000000007;

long long int tile(int i) {
	long long int& ret = dp[i];
	if (i <= 1) return ret  = 1;
	if (ret != -1) return ret;

	return ret = (tile(i - 1) + tile(i - 2)) % MOD;
}

long long int asymtile(int i) {
	if (i % 2 == 1)
		return (dp[i] - dp[i/2] + MOD) % MOD;
	long long int ret = dp[i];
	ret = (ret - dp[i/2] + MOD) % MOD;
	ret = (ret - dp[i/2-1] + MOD) % MOD;
	return ret;
}

int main() {
	int C; cin >> C;
	while (C--) {
		cin >> N;
		memset(dp, -1, sizeof(dp));
		tile(N);
		cout << asymtile(N) << '\n';
	}

	return 0;
}