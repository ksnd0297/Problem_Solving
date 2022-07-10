#include <iostream>
#include <queue>

using namespace std;

int map[9][9];
int Temp[9][9];

int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int N, M;

int BFS() {
	queue < pair<int, int>> virus;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			Temp[i][j] = map[i][j];
			if (map[i][j] == 2) virus.push({ i,j });
		}
	}

	while(!virus.empty()) {
		int y = virus.front().first;
		int x = virus.front().second;
		virus.pop();

		for (int i = 0; i < 4; i++) {
			int tempY = y + dir[i][0];
			int tempX = x + dir[i][1];

			if (tempY >= 0 && tempY < N && tempX >= 0 && tempX < M) {
				if (Temp[tempY][tempX] == 0) {
					Temp[tempY][tempX] = 2;
					virus.push({ tempY, tempX });
				}
			}
		}
	}

	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Temp[i][j] == 0) ret++;
		}
	}

	return ret;
}

int func(int wall) {
	if (wall == 3) { // º®ÀÌ 3°³
		return BFS();
	}

	int ans = 0;

	for (int i = 0; i < N * M; i++) {
		int y = i / M;
		int x = i % M;

		if (map[y][x] == 0) {
			map[y][x] = 1;
			ans = max(ans, func(wall + 1));
			map[y][x] = 0;
		}
	}
	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char ch; cin >> ch;
			map[i][j] = ch - '0';
		}
	}

	cout << func(0);

	return 0;
}

for (int i = 0; i < N; i++) {
	for (int j = 0; j < M; j++) {
		if (i >= 0 && i < N && j >= 0 && j < M) {
			// ...
		}
	}
}