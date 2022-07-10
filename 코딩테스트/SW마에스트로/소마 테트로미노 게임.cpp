#include <iostream>

using namespace std;

int arr[4][501];
bool check[4][501];

int block[19][3][2] = {
	{{1,0}, {2,0}, {3,0}},
	{{0,1}, {0,2}, {0,3}},
	{{1,0}, {0,1}, {1,1}},
	{{0,1}, {1,1}, {1,2}},
	{{1,0}, {1,-1}, {2,-1}},
	{{1,-1}, {1,0}, {0,1}},
	{{1,0}, {1,1}, {2,1}},
	{{1,0}, {2,0}, {2,1}},
	{{1,0}, {0,1}, {0,2}},
	{{0,1}, {1,1}, {2,1}},
	{{0,1}, {0,2}, {-1,2}},
	{{0,1}, {-1,1}, {-2,1}},
	{{1,0}, {1,1}, {1,2}},
	{{1,0}, {2,0}, {0,1}},
	{{0,1}, {0,2}, {1,2}},
	{{0,1}, {1,1}, {0,2}},
	{{0,1}, {-1,1}, {1,1}},
	{{0,1}, {-1,1}, {0,2}},
	{{1,0}, {1,1}, {2,0}}
};

int N;
int ans = 0;

int func(int yStart, int xStart, int ret) {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < N; x++) {
			if (!check[y][x] && arr[y][x] != 0) {
				check[y][x] = true;
				for (int i = 0; i < 19; i++) { // block 19개
					int sum = arr[y][x];
					bool flag = false; // 돌지 말지 체크
					for (int j = 0; !flag && j < 3; j++) { // 각각 좌표 3개 범위안에 있는지 일단 체크
						int tempY = y + block[i][j][0];
						int tempX = x + block[i][j][1];
						if (!(tempY >= 0 && tempY < 4 && tempX >= 0 && tempX < N) || check[tempY][tempX] || arr[y][x] == 0) flag = true; //범위를 벗어날경우 && 방문했던 곳을 방문할 경우
					}

					if (!flag) {
						for (int j = 0; j < 3; j++) {
							int tempY = y + block[i][j][0];
							int tempX = x + block[i][j][1];
							sum *= arr[tempY][tempX];
							check[tempY][tempX] = true;
						}
						ret += sum;
						ans = max(ans, func(y, x, ret));
						ret -= sum;
						for (int j = 0; j < 3; j++) {
							int tempY = y + block[i][j][0];
							int tempX = x + block[i][j][1];
							check[tempY][tempX] = false;
						}
					}
				}
				check[y][x] = false;
			}
		}
	}
	return ret;
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	func(0, 0, 0);
	cout << ans;

	return 0;
}