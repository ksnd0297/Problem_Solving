#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C;
int area[1501][1501];
bool check[1501][1501];

vector<pair<int, int>> swan; // 현재 백조의 위치 1백조 2백조
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

bool init() {
	queue<pair<int, int>> q;
	for (int i = 0; i < swan.size(); i++) q.push(swan[i]);
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int tempY = y + dir[i][0];
			int tempX = x + dir[i][1];
			if (tempY >= 0 && tempY < R && tempX >= 0 && tempX < C) {
				if (area[tempY][tempX] == 0) {
					area[tempY][tempX] = area[y][x];
					q.push({ tempY,tempX });
				}
				else if (area[tempY][tempX] != 0 && area[tempY][tempX] != -1 && area[y][x] != area[tempY][tempX]) {
					return true;
				}
			}
		}
	}
	return false;
} // 백조가 속해있는 공간 1로 변경

int start() {
	queue<pair<pair<int, int>, int>> ice; // 얼음의 좌표, 날짜
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (area[i][j] == -1) { // 빙판이
				for (int k = 0; k < 4; k++) {
					int tempY = i + dir[k][0];
					int tempX = j + dir[k][1];
					if (tempY >= 0 && tempY < R && tempX >= 0 && tempX < C) {
						if (area[tempY][tempX] == 1 || area[tempY][tempX] == 2 || area[tempY][tempX] == 0) { // 물과 붙어있을 때
							ice.push({ { tempY,tempX },1 });
							break;
						}
					}
				}
			}
		}
	}

	while (!ice.empty()) {
		int y = ice.front().first.first;
		int x = ice.front().first.second;
		int day = ice.front().second;
		ice.pop();

		for (int i = 0; i < 4; i++) {
			int tempY = y + dir[i][0];
			int tempX = x + dir[i][1];
			if (tempY >= 0 && tempY < R && tempX >= 0 && tempX < C) {
				if (area[tempY][tempX] == -1) {
					area[tempY][tempX] = area[y][x];
					if (area[y][x] != 0) {
						for (int j = 0; j < 4; j++) {
							int meetY = tempY + dir[j][0];
							int meetX = tempX + dir[j][1];
							if (meetY >= 0 && meetY < R && meetX >= 0 && meetX < C) {
								if (area[meetY][meetX] != -1 && area[meetY][meetX] != 0 && area[tempY][tempX] != area[meetY][meetX]) {
									return day;
								}
							}
						}
					}
					ice.push({ {tempY,tempX},day + 1 });
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;
	int count = 1;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char ch; cin >> ch;
			if (ch == '.') area[i][j] = 0; // 물
			else if (ch == 'X') area[i][j] = -1; // 빙판
			else if (ch == 'L') {
				area[i][j] = count; // 백조
				count++;
				swan.push_back({ i,j }); // 백조 위치 저장
			}
		}
	}

	if(init()) cout << 0;
	else cout << start();

	return 0;
}