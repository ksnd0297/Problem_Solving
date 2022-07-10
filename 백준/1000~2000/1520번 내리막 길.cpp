#include <iostream>
#include <string.h>

using namespace std;

int map[501][501];
int dp[501][501];
int N, M;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

int dfs(int y, int x) {
	int& ret = dp[y][x];
	if (dp[y][x] != -1) return ret;
	if (y == N - 1 && x == M - 1) return ret = 1;
	ret = 0;
	for (int i = 0; i < 4; i++) {
		int diry = y + dir[i][0]; int dirx = x + dir[i][1];
		if (diry >= 0 && diry < N && dirx >= 0 && dirx < M) { // 이동할 수 있는 방향인지 판단
			if (map[y][x] > map[diry][dirx]) { // 내리막길인지 판단
				ret += dfs(diry, dirx);
			}
		}
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dp, -1, sizeof(dp));

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	cout << dfs(0, 0);

	return 0;
}