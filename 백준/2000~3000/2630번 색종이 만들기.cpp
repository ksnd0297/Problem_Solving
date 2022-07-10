#include <stdio.h>
#pragma warning(disable : 4996)


int arr[129][129];

int recw(int x, int y, int len) {
	int countw = 0; //white count
	
	if (len == 0) return 0;

	for (int i = x; i < x + len; i++) {
		for (int j = y; j < y + len; j++) {
			if (arr[i][j] == 1) countw++;
		}
	}

	if (countw == 0) return 0;
	if (countw == (((x + len) - x) * ((y + len) - y))) return 1;

	return recw(x, y, len / 2) + recw(x + (len / 2), y, len / 2) + recw(x, y + (len / 2), len / 2) + recw(x + (len / 2), y + (len / 2), len / 2);
}

int recb(int x, int y, int len) {
	int countb = 0; //black count

	if (len == 0) return 0;

	for (int i = x; i < x + len; i++) {
		for (int j = y; j < y + len; j++) {
			if (arr[i][j] == 0) countb++;
		}
	}

	if (countb == 0) return 0;
	if (countb == (((x + len) - x) * ((y + len) - y))) return 1;

	return recb(x, y, len / 2) + recb(x + (len / 2), y, len / 2) + recb(x, y + (len / 2), len / 2) + recb(x + (len / 2), y + (len / 2), len / 2);
}

int main() {
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int black = recb(0, 0, N);
	int white = recw(0, 0, N);
	printf("%d\n", black);
	printf("%d\n", white);

	return 0;
}