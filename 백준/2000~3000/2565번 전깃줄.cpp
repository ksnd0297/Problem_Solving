#include <bits/stdc++.h>

using namespace std;

int N;
int arr[101];
int dp[101];

vector<pair<int, int>> ve;

int lis(int start) {
	int& ret = dp[start];
	if (ret != -1) return ret;

	ret = 1;
	for (int next = start + 1; next < N; next++) {
		if (arr[start] < arr[next]) ret = max(ret, lis(next) + 1);
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int A, B; cin >> A >> B;
		ve.push_back({ A,B });
	}
	sort(ve.begin(), ve.end());

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < N; i++) arr[i] = ve[i].second;

	for (int i = 0; i < N; i++) {
		lis(i);
	}
	
	int index = 0;
	int max = 0;
	for (int i = 0; i < N; i++) {
		if (max < dp[i]) {
			max = dp[i];
			index = i;
		}
	}
	cout << N - max;

	return 0;
}