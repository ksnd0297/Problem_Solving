#include <iostream>

using namespace std;

char arr[401][401];

void cur(int y, int x, int len) {
	if (len < 0) return;
	for (int i = y; i <= y + len; i++) {
		for (int j = x; j <= x + len; j++) {
			if (i != y && i != y + len && j != x && j != x + len) arr[i][j] = ' ';
			else arr[i][j] = '*';
		}
	}
	cur(y + 2, x + 2, len - 4);
}

int main(void)
{
	int N; cin >> N;
	cur(0, 0, (N - 1) * 4);
	for (int i = 0; i <= (N - 1) * 4; i++) {
		for (int j = 0; j <= (N - 1) * 4; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
	return 0;
}