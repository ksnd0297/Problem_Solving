#include <iostream>

using namespace std;

int N;

char arr[400][400];

int y, x;

int main(void)
{
	for (int i = 0; i < 400; i++) {
		for (int j = 0; j < 400; j++) {
			arr[i][j] = ' ';
		}
	}
	cin >> N; // 2
	if (N == 1) {
		cout << "*";
		return 0;
	}

	int Sero = 4 * N - 2; // 5
	int Garo = 4 * (N - 1); // 7

	int TempSero = Sero;
	int TempGaro = Garo;

	for (int i = 0; i <= Garo; i++) {
		arr[0][i] = '*';
	}

	int Arrow = 1;
	int Count = 0;
	while (1) {
		if (Garo <= 0 && Sero <= 0) break;
		Count = 0;
		while (Count != Sero && Sero != 0) {
			y += Arrow;
			arr[y][x] = '*';
			Count++;
		}
		Count = 0;
		while (Count != Garo && Garo != 0) {
			x += Arrow;
			arr[y][x] = '*';
			Count++;
		}

		Arrow *= -1;
		Garo -= 2; Sero -= 2;
	}
	for (int i = 0; i <= TempSero; i++) {
		for (int j = 0; j <= TempGaro; j++) {
			if (arr[i][j] == '*') cout << arr[i][j];
			else if(i != 1) cout << ' ';
			
		}
		cout << '\n';
	}

	return 0;
}