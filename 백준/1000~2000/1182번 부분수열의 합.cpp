#include <iostream>
#include <string.h>

using namespace std;

int N, S;
int arr[21];

int dp[21];

int sub(int sum, int index,int count) {
	if (sum == S && index == N && count != 0) return 1;
	if (index == N) return 0;

	int& ret = dp[index];
	if (ret != -1) return ret;

	return ret = sub(sum, index + 1, count) + sub(sum + arr[index], index + 1,count +1);
}

int main(void)
{
	cin >> N >> S;
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < N; i++) cin >> arr[i];
	int ans = sub(0, 0, 0);
	if (S == 0)ans--;
	cout << ans << '\n';

	return 0;
}