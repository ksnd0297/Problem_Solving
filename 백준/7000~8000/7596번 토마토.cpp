#include <iostream>
#include <queue>

using namespace std;

int map[101][101][101]; // 3차원 토마토 통
int N, M, H;
int day[101][101][101]; // 방문 했는지 날짜 체크하는 배열

typedef struct target {
	int h; int y; int x; // 높이 행 열
}target;

queue<target> q; // 높이 행 열

int vec[6][3] = { {-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1} }; //h y x

void bfs() {
	int k, x, y;
	while (!q.empty()) {
		k = q.front().h; x = q.front().x; y = q.front().y;
		q.pop();
		for (int i = 0; i < 6; i++) {
			if (k + vec[i][0] >= 0 && k + vec[i][0] < H && y + vec[i][1] >= 0 && y + vec[i][1] < N && x + vec[i][2] >= 0 && x + vec[i][2] < M) {
				if (map[k + vec[i][0]][y + vec[i][1]][x + vec[i][2]] == 0) {
					map[k + vec[i][0]][y + vec[i][1]][x + vec[i][2]] = 1;
					q.push({ k + vec[i][0],y + vec[i][1],x + vec[i][2] });
					day[k + vec[i][0]][y + vec[i][1]][x + vec[i][2]] = day[k][y][x] + 1;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N >> H; //행 열 높이 x y h

	for (int k = 0; k < H; k++) { //높이
		for (int i = 0; i < N; i++) { //행
			for (int j = 0; j < M; j++) { //열
				cin >> map[k][i][j];
				if (map[k][i][j] == 1) { q.push({ k,i,j });} // 높이 행 열
			}
		}
	}

	bfs();

	int max = 0;
	bool flag = false;
	for (int k = 0; k < H; k++) { //높이
		for (int i = 0; i < N; i++) { //행
			for (int j = 0; j < M; j++) { //열
				if (map[k][i][j] == 0 && day[k][i][j] == 0) flag = true;
				if (max < day[k][i][j]) max = day[k][i][j];
			}
		}
	}
	if (flag) cout << -1;
	else cout << max;
	
	return 0;
}