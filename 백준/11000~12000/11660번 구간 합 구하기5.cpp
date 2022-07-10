#include <iostream>

using namespace std;

int map[1026][1026];
int dp[1026][1026];

int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j == 0) dp[i][j] = map[i][j];
			else dp[i][j] = dp[i][j - 1] + map[i][j];
		}
	}

	int x1, y1, x2, y2;
	for (int i = 0; i < M; i++) {
		cin >> y1 >> x1 >> y2 >> x2;
		x1 -= 1; y1 -= 1; x2 -= 1; y2 -= 1;
		int sum = 0;
		for (int y = y1; y <= y2; y++) {
			if (x1 == 0) sum += dp[y][x2];
			else sum += dp[y][x2] - dp[y][x1-1];
		}
		cout << sum << '\n';
	}

	return 0;
}