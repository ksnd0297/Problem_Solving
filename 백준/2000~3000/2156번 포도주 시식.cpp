#include <iostream>
#include <algorithm>

using namespace std;

int arr[10001];
int n;
long long int dp[10001][2];


int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	dp[0][0] = arr[0];
	dp[1][0] = arr[1];
	dp[1][1] = arr[0] + arr[1];
	dp[2][0] = dp[0][0] + arr[2];
	dp[2][1] = dp[1][0] + arr[2];

	long long int ans = dp[1][1];
	for (int i = 3; i < n; i++) {
		dp[i][0] = max({ dp[i - 2][1],dp[i - 2][0],dp[i - 3][0],dp[i - 3][1] }) + arr[i];
		dp[i][1] = dp[i - 1][0] + arr[i];
		if (ans < dp[i][0]) ans = dp[i][0];
		if (ans < dp[i][1]) ans = dp[i][1];
	}
	cout << ans;
	return 0;
}