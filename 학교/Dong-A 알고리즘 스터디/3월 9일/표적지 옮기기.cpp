#include <iostream>

using namespace std;

int arr[2501][2501];

int N, M;

bool func(int y, int x,int length) {
	if (length == 10) return true;
	int count = 0;
	for (int i = y - length; i <= y + length; i++) {
		for (int j = x - length; j <= x + length; j++) {
			if (i >= 0 && i < N && j >= 0 && j < M) {
				if ((i == y-length || i == y+length) || (j == x-length || j == x + length)) {
					if (arr[i][j] == 1) count++;
				}
			}
		}
	}
	if (count == 1) return func(y, x,length+1);
	else return false;
	
}

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char ch; cin >> ch;
			arr[i][j] = ch - '0';
		}
	}

	bool flag = false;
	for (int i = 0; !flag && i < N; i++) {
		for (int j = 0; !flag && j < M; j++) {
			if (arr[i][j]) {
				if (func(i, j, 0)) {
					cout << i << ' ' << j;
					flag = true;
				}
			}
		}
	}
	if (!flag) cout << -1;

	return 0;
}