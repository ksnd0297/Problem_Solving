#include <iostream>
#include <algorithm>

using namespace std;

int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
bool check[26][26];
int map[26][26];
int N;
int danji[626];

void dfs(int y, int x, int cnt) {
	check[y][x] = true;
	danji[cnt]++;
	for (int i = 0; i < 4; i++) {
		int tempY = y + dir[i][0];
		int tempX = x + dir[i][1];
		if (tempY >= 0 && tempY < N && tempX >= 0 && tempX < N) {
			if (map[tempY][tempX] == 1 && !check[tempY][tempX]) dfs(tempY, tempX, cnt);
		}
	}
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char ch; cin >> ch;
			map[i][j] = ch - '0';
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && !check[i][j]) {
				dfs(i, j, cnt);
				cnt++;
			}
		}
	}
	sort(danji, danji + cnt);
	cout << cnt << '\n';
	for (int i = 0; i < cnt; i++) cout << danji[i] << '\n';
	return 0;
}