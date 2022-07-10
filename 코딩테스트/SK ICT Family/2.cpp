#include <string>
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int N;
int arr[1001][1001];
bool clockwise = false;
queue<tuple<int, int, int, int, int, int>> pos;

void func(int n) {
	queue<tuple<int, int, int, int, int, int >> temp;
	while (!pos.empty()) {
		tuple<int, int, int, int, int, int> t = pos.front();
		pos.pop();
		int y = get<0>(t); int x = get<1>(t);
		int gase = get<2>(t); // 가로 세로
		int arrow = get<3>(t); // 방향
		int cnt = get<4>(t); // 돌아야 할 개수
		int turnCnt = get<5>(t);
		int gap = arr[y][x];
		for (int j = 0; j < cnt; j++) {
			if (gase == 1) { // 가로방향
				arr[y][x] = gap + j;
				if (j == cnt - 1) {
					if (clockwise == false) { // 반시계
						if (turnCnt != 1)
							temp.push({ y,x, gase * -1, arrow * -1, cnt - 1, turnCnt + 1 }); // 정
						else
							temp.push({ y,x, gase * -1, arrow * -1, cnt - 2, 0 }); // 정
					}
					else { // 시계
						if (turnCnt != 1)
							temp.push({ y,x, gase * -1, arrow, cnt - 1,turnCnt + 1 });
						else
							temp.push({ y,x, gase * -1, arrow, cnt - 2,0 });
					}
				}
				x += arrow;
			}
			else if (gase == -1) { // 세로방향
				arr[y][x] = gap + j;
				if (j == cnt - 1) {
					if (clockwise == false) { // 반시계
						if (turnCnt != 1)
							temp.push({ y,x, gase * -1, arrow, cnt - 1, turnCnt + 1 });
						else
							temp.push({ y,x, gase * -1, arrow, cnt - 2, 0 });
					}
					else { // 시계
						if (turnCnt != 1)
							temp.push({ y,x, gase * -1, arrow * -1,cnt - 1, turnCnt + 1 });
						else
							temp.push({ y,x, gase * -1, arrow * -1,cnt - 2, 0 });
					}
				}
				y += arrow;

			}
		}
	}
	pos = temp;
}

int main(void) {
	N = 6;
	N--;
	// y, x ,(가로, 세로), (정 역)  //////////// 1 : 가로, 정 -1 :세로, 역
	if (clockwise == true) { // 시계
		pos.push({ 0, 0,1,1, N ,0 }); // 가로 정
		pos.push({ 0, N, -1, 1, N,0 }); // 세로 정
		pos.push({ N, 0,-1,-1, N,0 }); // 세로 역
		pos.push({ N, N,1,-1, N,0 }); // 가로 역

	}
	else if (clockwise == false) { // 반시계
		pos.push({ 0, 0, -1,1, N,0 }); // 세로 정
		pos.push({ 0, N,1, -1, N,0 });  // 가로 역
		pos.push({ N, 0,1, 1, N ,0 });  // 가로 정
		pos.push({ N, N,-1,-1, N,0 });  // 세로 역
	}
	arr[0][0] = 1;
	arr[0][N] = 1;
	arr[N][0] = 1;
	arr[N][N] = 1;
	bool flag = false;
	while (N > 1) {
		func(N);
		N-=2;
	}
	int a = 10;
	return 0;
}