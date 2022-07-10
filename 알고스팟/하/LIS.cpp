#include <iostream>

using namespace std;

int arr[501];
int dp[501];
int C, N;

int func(int idx) {
	int& ret = dp[idx];
	if (idx == N - 1) return 1;
	if (ret != 0) return ret;

	for (int i = idx + 1; i < N; i++) {
		if (arr[idx] < arr[i]) {
			ret += func(i);
		}
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> C;
	while (C--) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> arr[i];
		cout << func(0) << '\n';
	}
	return 0;
}