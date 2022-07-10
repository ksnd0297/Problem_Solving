#include <iostream>

using namespace std;

long long int dp[110];

int main() {
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	dp[6] = 3;

	for (int i = 7; i < 110; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	int N; cin >> N;
	while (N--) {
		int num; cin >> num;
		cout << dp[num] << '\n';
	}
}