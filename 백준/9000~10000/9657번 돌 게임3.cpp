#include <iostream>

using namespace std;

int dp[1010];

int main(void)
{
	dp[1] = 1; dp[3] = 1; dp[4] = 1;
	for (int i = 1; i <= 1000; i++) {
		if (dp[i] == 0) {
			dp[i + 1] = 1;
			dp[i + 3] = 1;
			dp[i + 4] = 1;
		}
	}
	int N; cin >> N;
	if (dp[N]) cout << "SK";
	else cout << "CY";
	return 0;
}