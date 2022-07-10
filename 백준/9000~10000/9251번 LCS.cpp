#include <iostream>
#include <string>

using namespace std;

string A, B;

int dp[1001][1001];

int main(void)
{
	cin >> A >> B;

	int ans = 0;
	for (int i = 1; i <= A.size(); i++) {
		for (int j = 1; j <= B.size(); j++) {
			if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;

	return 0;
}