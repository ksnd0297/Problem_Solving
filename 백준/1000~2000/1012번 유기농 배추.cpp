#include <iostream>

using namespace std;

int map[51][51]; // y , x

int N, M, K;// 가로 세로 배추의 개수

int dfs(int y, int x) {
	if ((y < 0 || y >= M) || (x <0 || x >= N)) return 0;
	if (map[y][x] == 0) return 0;
	if (map[y][x] == 1) map[y][x] = 0;
	return dfs(y + 1, x) + dfs(y, x + 1) + dfs(y - 1, x) + dfs(y, x - 1);
}

int main() {
	int C; cin >> C;
	while (C--) {
		cin >> N >> M >> K;
		while (K--) {
			int x, y; cin >> x >> y;
			map[y][x] = 1;
		}

		int count = 0; // 배추흰지렁이 체크
		for (int i = 0; i < M; i++) { // 세로 map[i][]
			for (int j = 0; j < N; j++) { // 가로 map[][j]
				if (map[i][j]) {
					int A = dfs(i, j); count++;
				}
			}
		}
		cout << count << '\n';
	}

}