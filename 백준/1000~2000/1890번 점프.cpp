#include <iostream>
#include <string.h>

using namespace std;

long long int dp[101][101];
int map[101][101];

int N;

long long int func(int y, int x) {
	if (!(y >= 0 && y < N && x >= 0 && x < N)) return 0;
	if (y == N - 1 && x == N - 1) return 1;
	long long int& ret = dp[y][x];
	if (map[y][x] == 0) return ret = 0;
	if (ret != -1) return ret;
	
	ret = func(y + map[y][x], x) + func(y, x + map[y][x]);
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));

	cout << (long long int)func(0, 0);
	return 0;
}