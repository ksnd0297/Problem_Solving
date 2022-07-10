#include <iostream>

using namespace std;

int map[550][550];

int arr[19][3][2] = { 
	{{0,1},{0,2},{0,3}},
	{{1,0},{2,0},{3,0}},
	{{1,0},{0,1},{1,1}},
	{{1,0},{2,0},{2,1}},
	{{0,1},{0,2},{1,0}},
	{{0,1},{1,1},{2,1}},
	{{1,0},{1, -1},{1,-2}}, 
	{{1,0},{2,0},{2,-1}}, 
	{{1,0},{1,1},{1,2}},
	{{1,0},{2,0},{0,1}},
	{{0,1},{0,2},{1,2}},
	{{1,0},{1,1},{2,1}},
	{{0,1},{1,0},{1,-1}}, 
	{{1,0},{1,-1},{2,-1}}, 
	{{0, 1},{1,1},{1,2}},
	{{0, 1},{0, 2},{1,1}},
	{{1,0},{2,0},{1,-1}},
	{{1,0},{1,-1},{1,1}},
	{{1,0},{1,1},{2,0}}
};

int main(void) {
	int N, M; cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}

	int max = 0; int sum = 0;
	bool flag = false;
	for (int y = 0; y < N; y++) { // y
		for (int x = 0; x < M; x++) { // x
			for (int k = 0; k < 19; k++) { 
				flag = false; sum = map[y][x];
				for (int l = 0;!flag && l < 3; l++) {
					if (y + arr[k][l][0] >= 0 && y + arr[k][l][0] < N && x + arr[k][l][1] >= 0 && x + arr[k][l][1] < M) {
						sum += map[y + arr[k][l][0]][x + arr[k][l][1]];
					}
					else flag = true;
				}
				if (flag) continue;
				else if (max < sum) max = sum;
			}
		}
	}
	cout << max;
	return 0;
}