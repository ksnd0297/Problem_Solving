#include <iostream>

using namespace std;

int map[101][101];
int cache[101][101];

int C;
int N;

int dir[2][2] = { {0,1},{1,0} };

int dp(int y, int x) {
	int& ret = cache[y][x];
	if (!(y >= 0 && y < N && x >= 0 && x < N)) return 0;
	if (y == N - 1 && x == N - 1) return 1;
	if (ret != -1) return ret;

	ret = (dp(y + map[y][x], x) || dp(y, x + map[y][x]));
	return ret;
}

int main(void)
{
	cin >> C;
	while (C--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				cache[i][j] = -1;
			}
		}

		if (dp(0, 0)) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}