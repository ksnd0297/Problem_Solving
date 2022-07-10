#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int N, M;
int map[1001][1001];
int dp[1001][1001];

int func(int y, int x) {
	if (!(y >= 0 && y < N && x >= 0 && x < M)) return 0;
	int& ret = dp[y][x];
	if (ret != -1) return ret;
	ret = max({ func(y + 1, x), func(y, x + 1), func(y + 1, x + 1) }) + map[y][x];
	return ret;
}

int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << func(0, 0);
	return 0;
}