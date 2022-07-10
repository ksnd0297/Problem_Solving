#include <bits/stdc++.h>

using namespace std;

char arr[21][21];
bool check[21][21];

int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

bool alpha[26];

int R, C;
int ans = 1;

int dfs(int y, int x, int depth) {

	for (int i = 0; i < 4; i++) {
		int tempY = y + dir[i][0];
		int tempX = x + dir[i][1];

		if (tempY >= 0 && tempY < R && tempX >= 0 && tempX < C) {
			if (!check[tempY][tempX] && !alpha[arr[tempY][tempX] - 'A']) {
				check[tempY][tempX] = true; alpha[arr[tempY][tempX] - 'A'] = true;
				ans = max(ans, dfs(tempY, tempX, depth + 1));
				check[tempY][tempX] = false; alpha[arr[tempY][tempX] - 'A'] = false;
			}
		}
	}
	return depth;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}

	alpha[arr[0][0] - 'A'] = true; check[0][0] = true;
	dfs(0, 0, 1);
	cout << ans;

	return 0;
}