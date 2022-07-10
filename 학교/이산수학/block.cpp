#include <iostream>
#pragma warning(disable : 4996)

using namespace std;

int T;
int N;

int arr[1001][1001];

int func(int y, int x) {
	if (arr[y + 1][x] != -1 && arr[y + 1][x + 1] != -1 && y + 1 < N) {
		return (arr[y + 1][x] + arr[y + 1][x + 1] + 100) % 100;
	}
	else if (arr[y - 1][x] != -1 && arr[y][x + 1] != -1 && y - 1 >= 0 && x + 1 <= y) {
		return (arr[y - 1][x] - arr[y][x + 1] + 100) % 100;
	}
	else if (arr[y - 1][x - 1] != -1 && arr[y][x - 1] != -1 && y - 1 >= 0 && x - 1 >= 0) {
		return (arr[y - 1][x - 1] - arr[y][x - 1] + 100) % 100;
	}
	else return -1;
}

int main(void)
{
	freopen("block.inp", "r", stdin);
	freopen("block.out", "w", stdout);

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= i; j++) {
				cin >> arr[i][j];
			}
		}



		int y = 0;
		int x = 0;
		int length = N;
		do {
			int tempy = y;
			int tempx = x;
			for (int i = 1; i <= length; i++) {
				if (arr[tempy][tempx] == -1) {
					arr[tempy][tempx] = func(tempy, tempx);
				}
				tempy++; tempx++;
			}
			y++;
		} while (length--);

		y = N-1;
		x = 0;
		length = 1;
		do {
			int tempy = y;
			int tempx = x;
			for (int i = 1; i <= length; i++) {
				if (arr[tempy][tempx] == -1) {
					arr[tempy][tempx] = func(tempy, tempx);
				}
				tempy++; tempx++;
			}
			y--;
			length++;
		} while (length != N);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= i; j++) {
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}