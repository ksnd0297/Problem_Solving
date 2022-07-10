#include <bits/stdc++.h>

using namespace std;

int arr[101][101];
bool check[101][101];
int dir[4][2] = { {-1,0},{1,0},{0, -1}, {0, 1} };

int N, M;
int W, B; // W : 1 B : 0

int Count = 0;

void DFS(int y, int x) {
	check[y][x] = true;
	Count++;

	for (int i = 0; i < 4; i++) {
		int tempY = y + dir[i][0];
		int tempX = x + dir[i][1];
		if (tempY >= 0 && tempY < N && tempX >= 0 && tempX < M) {
			if (!check[tempY][tempX]) {
				if (arr[y][x] == arr[tempY][tempX]) {
					DFS(tempY, tempX);
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char ch; cin >> ch;
			if (ch == 'W') arr[i][j] = 1;
			else arr[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!check[i][j]) {
				DFS(i, j);
				if (arr[i][j] == 0) B += Count * Count;
				else W += Count * Count;
				Count = 0;
			}
		}
	}
	cout << W << ' ' << B;
}