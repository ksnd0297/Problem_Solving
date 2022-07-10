#include <iostream>
#include <string.h>


using namespace std;

int map[101][101];
int check[101][101];

int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

int N, M;

void DFS(int y, int x) {
	check[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int tempY = y + dir[i][0];
		int tempX = x + dir[i][1];

		if (tempY >= 0 && tempY < N && tempX >= 0 && tempX <= M) {
			if (!check[tempY][tempX]) {
				if (map[tempY][tempX] == 0) {
					DFS(tempY, tempX);
				}
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	int ans = 0;
	while (1) {
		// 4 방향 DFS
		DFS(0, 0); 
		DFS(0, M - 1);
		DFS(N - 1, 0);
		DFS(N - 1, M - 1);

		bool flag = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1) { // 얼음이 존재
					flag = true;
					int cnt = 0;
					if (i - 1 >= 0 && check[i - 1][j]) cnt++;
					if (i + 1 < N && check[i + 1][j]) cnt++;
					if (j - 1 >= 0 && check[i][j - 1]) cnt++;
					if (j + 1 < M && check[i][j + 1]) cnt++;
					
					if (cnt >= 2) map[i][j] = 0;
				}
			}
		}
		if (!flag) break;
		memset(check, 0, sizeof(check));
		ans++;
	}

	cout << ans;

	return 0;
}