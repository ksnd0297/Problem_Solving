#include <iostream>

using namespace std;

char arr[65][65];

void div(int x, int y, int len) {
	if (len == 0) return;
	int one = 0; int zero = 0;
	for (int i = x; i < x+len; i++) {
		for (int j = y; j < y+len; j++) {
			if (arr[j][i] == '0') zero++;
			else if (arr[j][i] == '1') one++;
		}
	}
	
	if (zero == len * len) cout << 0;
	else if (one == len * len) cout << 1;
	else {
		cout << "(";
		div(x, y, len / 2);
		div(x + (len / 2), y, len / 2);
		div(x, y + (len / 2), len / 2);
		div(x + len / 2, y + len / 2, len / 2);
		cout << ")";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	div(0, 0, N);

	return 0;
}