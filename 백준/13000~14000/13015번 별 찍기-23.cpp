#include <iostream>

using namespace std;

int N;

char arr[500][500];

int main(void)
{
	cin >> N;
	int Garo = (2 * N - 3) + N;
	int Sero = (2 * N - 3) + 1;

	pair<int, int> D[4] = { {0,0},{0,Garo},{Sero,0},{Sero,Garo} };

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < N; j++) {
			int y = D[i].first;
			int x = D[i].second;
			arr[y][x + j] = '*';
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < N; j++) {
			int StartY = D[i].first;
			int StartX = D[i].second;
			int EndX = D[i].second + (N - 1);
			if (i == 0) {
				arr[StartY + j][StartX + j] = '*';
				arr[StartY + j][EndX + j] = '*';
			}
			else if (i == 1) {
				arr[StartY + j][StartX - j] = '*';
				arr[StartY + j][EndX - j] = '*';
			}
			else if (i == 2) {
				arr[StartY - j][StartX + j] = '*';
				arr[StartY - j][EndX + j] = '*';
			}
			else if (i == 3) {
				arr[StartY - j][StartX - j] = '*';
				arr[StartY - j][EndX - j] = '*';
			}
		}
	}

	int P = Garo + N;
	for (int i = 0; i < (2*N -1); i++) {
		if (i < N)P--;
		else P++;
		for (int j = 0; j <= P; j++) {
			if (arr[i][j] == '*') cout << arr[i][j];
			else cout << ' ';
		}
		cout << '\n';
	}

	return 0;
}