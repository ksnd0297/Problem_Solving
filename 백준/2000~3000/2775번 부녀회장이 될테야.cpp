#include <iostream>

using namespace std;

int arr[16][16];

int main() {
	for (int i = 0; i < 16; i++) {
		arr[0][i] = i + 1;
		arr[i][0] = 1;
	}

	for (int i = 1; i < 16; i++) {
		for (int j = 1; j < 16; j++) {
			arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
		}
	}

	int TC;
	cin >> TC;
	while (TC--) {
		int K, N;
		cin >> K >> N;
		cout << arr[K][N-1] << endl;
	}
	return 0;
}