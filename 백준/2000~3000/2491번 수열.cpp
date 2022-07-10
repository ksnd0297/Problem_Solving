#include <iostream>
using namespace std;

int arr[100001];
int dp[100001][2]; // up & down
int main(void)
{
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i][0] = 1; dp[i][1] = 1;
	}
	
	int max = 0;
	bool flag = false; // 자기자신 보다 큰 값이 들어오는지 판단
	for (int i = 1; i < N; i++) {
		if (arr[i] > arr[i - 1]) dp[i][0] = dp[i - 1][0] + 1;
		else if (arr[i] < arr[i - 1]) dp[i][1] = dp[i - 1][1] + 1;
		else if (arr[i] == arr[i - 1]) {
			dp[i][0] = dp[i - 1][0] + 1;
			dp[i][1] = dp[i - 1][1] + 1;
		}
	}
	for (int i = 0; i < N; i++) {
		if (max < dp[i][0]) max = dp[i][0];
		if (max < dp[i][1]) max = dp[i][1];
	}
	cout << max;
	return 0;
}