#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int arr[21][21];
bool visit[21][21];

int N;
int sharkSize = 2;
int fishCount = 0;

int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };

int sharkY;
int sharkX;
int ansTime;

struct POS {
	int y;
	int x;
	int time;

	POS(int y, int x, int time) {
		this->y = y;
		this->x = x;
		this->time = time;
	}

	bool operator<(const POS& i) const { // false ÀÏ¶§ º¯°æ true ¸ØÃã
		if (this->time == i.time) {
			if (this->y > i.y) return true;
			else if (this->y < i.y) return false;
			else {
				if (this->x > i.x) return true;
				else if (this->x < i.x) return false;
			}
		}
		return this->time > i.time;
	}
};

priority_queue<POS, vector<POS>> pq;
queue<POS> q;

bool BFS(int y, int x, int time) {
	memset(visit, false, sizeof(visit));

	q.push(POS(y, x, time));
	do {
		POS pos = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int tempY = pos.y + dir[i][0];
			int tempX = pos.x + dir[i][1];
			if (tempY >= 0 && tempY < N && tempX >= 0 && tempX < N) {
				if ((arr[tempY][tempX] == sharkSize || arr[tempY][tempX] == 0) && !visit[tempY][tempX]) {
					visit[tempY][tempX] = true; q.push(POS(tempY, tempX, pos.time + 1));
				}
				else if (arr[tempY][tempX] != 0 && arr[tempY][tempX] < sharkSize && !visit[tempY][tempX]) {
					visit[tempY][tempX] = true;
					pq.push(POS(tempY, tempX, pos.time + 1));
				}
			}
		}
	} while (!q.empty());

	if (pq.empty()) return false;
	else {
		POS fish = pq.top(); pq.pop();
		arr[fish.y][fish.x] = 0;
		sharkY = fish.y; sharkX = fish.x;
		ansTime += fish.time; fishCount++;
		if (fishCount == sharkSize) {
			sharkSize++; fishCount = 0;
		}
	}
	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				sharkY = i; sharkX = j;
				arr[i][j] = 0;
			}
		}
	}
	while (BFS(sharkY, sharkX, 0)) {
		while (!q.empty()) q.pop();
		while (!pq.empty()) pq.pop();
	}

	cout << ansTime;

	return 0;
}