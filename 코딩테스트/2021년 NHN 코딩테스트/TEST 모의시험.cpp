#include <iostream>
#include <algorithm>

using namespace std;

int matrix[11][11];
int sizeOfMatrix;

bool check[11][11];

int matCnt[11]; // 단지 번호의 수



int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

void dfs(int y, int x, int idx) {
	matCnt[idx]++;
	for (int i = 0; i < 4; i++) {
		int tempY = y + dir[i][0];
		int tempX = x + dir[i][1];
		if (tempY >= 0 && tempY < sizeOfMatrix && tempX >= 0 && tempX < sizeOfMatrix) {
			if (matrix[tempY][tempX]) {
				if (!check[tempY][tempX]) {
					check[tempY][tempX] = true;
					dfs(tempY, tempX, idx);
				}
			}
		}
	}
}

void solution() {
	int idx = 0;
	for (int i = 0; i < sizeOfMatrix; i++) {
		for (int j = 0; j < sizeOfMatrix; j++) {
			if (matrix[i][j] == 1 && !check[i][j]) {
				check[i][j] = true;
				dfs(i, j, idx); idx++;
			}
		}
	}
	sort(matCnt, matCnt + idx);
	cout << idx << '\n';
	for (int i = 0; i < idx; i++) {
		cout << matCnt[i] << ' ';
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> sizeOfMatrix;
	for (int i = 0; i < sizeOfMatrix; i++) {
		for (int j = 0; j < sizeOfMatrix; j++) {
			cin >> matrix[i][j];
		}
	}

	solution();
	return 0;
}