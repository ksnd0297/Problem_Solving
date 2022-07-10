#include <iostream>

using namespace std;

int map[2188][2188]; // 3^7 = 2187

int mione; // -1
int zero; // 0
int one; // 1

int div(int y, int x,int len) {
	int tempmione = 0;
	int tempzero = 0;
	int tempone = 0;
	for (int i = y; i < y + len; i++) {
		for (int j = x; j < x + len; j++) {
			if (map[i][j] == -1) tempmione++;
			else if (map[i][j] == 0) tempzero++;
			else if (map[i][j] == 1) tempone++;
		}
	}

	if (tempmione == len * len) {
		mione++; return 0;
	}
	else if (tempzero == len * len) {
		zero++; return 0;
	}
	else if (tempone == len * len) {
		one++; return 0;
	}
	return div(y, x, len / 3) + div(y + len / 3, x, len / 3) + div(y + (2 * len) / 3, x, len / 3) + div(y, x + len / 3, len / 3) + div(y + len / 3, x + len / 3, len / 3) + div(y + (2 * len) / 3, x + len / 3, len / 3) + div(y, x + (2 * len) / 3, len / 3) + div(y + len / 3, x + (2 * len) / 3, len / 3) + div(y + (2 * len) / 3, x + (2 * len) / 3, len / 3);
}

int main() {
	int len; // 배열의 길이
	cin >> len;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			cin >> map[i][j];
		}
	}

	int temp = div(0, 0,len);

	cout << mione << '\n';
	cout << zero << '\n';
	cout << one << '\n';

	return 0;
}