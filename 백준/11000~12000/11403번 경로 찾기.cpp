#include <iostream>

using namespace std;

int map[101][101];
bool check[101][101];

int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (!map[i][j]) map[i][j] = 123456789;
			else check[i][j] = true;
		}
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] > map[i][k] + map[k][j]) {
					map[i][j] = map[i][k] + map[k][j];
					check[i][j] = true;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << check[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;

}