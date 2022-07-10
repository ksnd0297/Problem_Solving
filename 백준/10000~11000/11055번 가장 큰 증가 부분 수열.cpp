#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;

int dp[1001];

int lds(int start) {
	int& ret = dp[start];

	if (ret != -1) return ret;

	ret = A[start];
	for (int next = start + 1; next < N; next++) {
		if (A[start] < A[next]) ret = max(ret, lds(next) + A[start]);
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int Num; cin >> Num;
		A.push_back(Num);
	}

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < N; i++) {
		if (dp[i] == -1) lds(i);
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans;

	return 0;
}