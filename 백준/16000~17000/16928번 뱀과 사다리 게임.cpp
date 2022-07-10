#include <iostream>
#include <queue>

using namespace std;

int ladder[110]; // 사다리를 탔을 때 올라가는 곳
int snake[110]; // 뱀을 탔을 때 내려가는 곳

int check[110]; // 주사위를 던져 갈 수 있는 값

queue<int> q;

void bfs(int x) {
	q.push(x);
	while (!q.empty()) {
		int tar = q.front(); q.pop();
		for (int i = 1; i <= 6; i++) {
			if (check[tar + i] == 123456789) {
				if (tar + i > 100) break;

				if (ladder[tar + i]) { //사다리가 있는 위치는 무조건 타고 올라감
					check[tar + i] = check[tar] + 1;
					check[ladder[tar + i]] = min(check[tar + i], check[ladder[tar + i]]);
					q.push(ladder[tar + i]);
				}
				else if (snake[tar + i]) { //뱀이 있는 위치는 무조건 타고 내려감
					check[tar + i] = check[tar] + 1;
					check[snake[tar + i]] = min(check[tar + i], check[snake[tar + i]]);
					q.push(snake[tar + i]);
				}
				else {
					q.push(tar + i); //그 외에는 주사위를 굴림
					check[tar + i] = min(check[tar + i], check[tar] + 1);
				}
			}
		}
	}
}

int main() {
	int N, M; cin >> N >> M;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b; ladder[a] = b;
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b; snake[a] = b;
	}
	check[1] = 0;
	for (int i = 2; i < 110; i++) check[i] = 123456789;
	bfs(1);

	cout << check[100];
	return 0;
}