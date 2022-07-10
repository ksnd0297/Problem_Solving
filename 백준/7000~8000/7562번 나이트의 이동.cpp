#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int T;
int l;

int startY, startX;
int targetY, targetX;

bool check[301][301];


int dir[8][2] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1} };

int bfs(int Y, int X) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ make_pair(Y, X), 0 });
	check[Y][X] = true;
	while (!q.empty()) {
		int Y = q.front().first.first;
		int X = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (Y == targetY && X == targetX) return cnt;

		for (int i = 0; i < 8; i++) {
			int tempY = Y + dir[i][0];
			int tempX = X + dir[i][1];

			if (tempY >= 0 && tempY < l && tempX >= 0 && tempX < l) {
				if (!check[tempY][tempX]) {
					q.push({ make_pair(tempY,tempX), cnt + 1 });
					check[tempY][tempX] = true;
				}
			}
		}
	}
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--) {
		cin >> l;
		cin >> startY >> startX;
		cin >> targetY >> targetX;

		cout << bfs(startY, startX) << '\n';
		memset(check, false, sizeof(check));
	}

	return 0;
}