#include <iostream>
#include <string.h>

using namespace std;

int dp[101][101];
int map[101][101];
int C;
int n;

int func(int y, int x, int depth) {
	if (depth == n) return dp[y][x] = map[y][x];
	int& ret = dp[y][x];
	if (ret != -1) return ret;
	return ret = max(func(y + 1, x, depth + 1), func(y + 1, x + 1, depth + 1)) + map[y][x];
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> C;
	while (C--) {
		memset(dp, -1, sizeof(dp));
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				cin >> map[i][j];
			}
		}
		cout << func(0, 0, 1) << '\n';
	}
	return 0;
}