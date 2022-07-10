#include <iostream>

using namespace std;

char star[6561][6561];
int N;

int div(int y, int x, int len) {
	if (len == 1) {
		star[y][x] = '*';
		return 0;
	}
	return div(y, x, len / 3) + div(y + len / 3, x, len / 3) + div(y + (2 * len) / 3, x, len / 3) + div(y, x + len / 3, len / 3) + div(y + (2 * len) / 3, x + len / 3, len / 3) + div(y, x + (2 * len) / 3, len / 3) + div(y + len / 3, x + (2 * len) / 3, len / 3) + div(y + (2 * len) / 3, x + (2 * len) / 3, len / 3);
}

int main(void)
{
	cin >> N;
	div(0, 0, N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (star[i][j] == '*') cout << '*';
			else cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}