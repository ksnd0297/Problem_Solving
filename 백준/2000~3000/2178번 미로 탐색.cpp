#include <iostream>

using namespace std;

char arr[101][101];
int dist[101][101];
int N, M;

int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int tempY = y + dir[i][0];
		int tempX = x + dir[i][1];
		if (tempY >= 0 && tempY < N && tempX >= 0 && tempX < M) {
			if (arr[tempY][tempX] == '1') {
				if (dist[tempY][tempX] == 0 || dist[tempY][tempX] > dist[y][x] + 1) {
					dist[tempY][tempX] = dist[y][x] + 1;
					dfs(tempY, tempX);
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
			cin >> arr[i][j];
		}
	}
	dist[0][0] = 1;
	dfs(0, 0);
	cout << dist[N - 1][M - 1];
	return 0;
}