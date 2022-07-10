#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[305][305];
int dp[305][305];

int dir[2][2] = { {1,0},{0,1} };

int func(int y, int x) {
	int& ret = dp[y][x];
	if (arr[y + 1][x] == 0 && arr[y][x + 1] == 0) return ret = 1;
	if (ret != 0) return ret;

	for (int i = 0; i < 2; i++) {
		int tempY = y + dir[i][0];
		int tempX = x + dir[i][1];

		if (tempY >= 0 && tempY < N && tempX >= 0 && tempX < M) {
			ret = max(ret, func(tempY, tempX) + 1);
		}
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (dp[i][j] == 0 && arr[i][j] == 1) func(i, j);
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans;

	return 0;
}