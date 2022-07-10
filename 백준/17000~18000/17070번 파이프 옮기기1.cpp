#include <bits/stdc++.h>

using namespace std;

int N;
int arr[17][17];
int dp[17][17][4];

int dir[3][2] = { {1,0},{1,1},{0,1} };

void DFS(int y, int x) {
	if (y >= 0 && y < N && x >= 0 && x < N) {
		if (arr[y][x] != 1) {
			dp[y][x][1] += dp[y][x - 1][1] + dp[y - 1][x - 1][3];
			dp[y][x][2] += dp[y][x - 1][1] + dp[y - 1][x][3] + dp[y - 1][x - 1][2];
			dp[y][x][3] += dp[y - 1][x][3] + dp[y - 1][x - 1][2];

			for (int i = 0; i < 3; i++) {
				int tempY = y + dir[i][0];
				int tempX = x + dir[i][1];

				DFS(tempY, tempX);
			}
		}
	}
}

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	dp[1][2][1] = 1;

	DFS(1, 2);
	cout << dp[N][N][1] + dp[N][N][2] + dp[N][N][3];

	return 0;
}