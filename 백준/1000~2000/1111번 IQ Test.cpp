#include <iostream>
using namespace std;

int N;
int arr[51];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	if (N < 3) {
		if (arr[0] == arr[1] && N != 1) {
			cout << arr[0]; return 0;
		}
		else {
			cout << 'A'; return 0;
		}
	}

	double a, b;
	if (arr[1] == arr[0]) {
		for (int i = 0; i < N; i++) {
			if (arr[0] != arr[i]) {
				cout << 'B'; return 0;
			}
		}
		cout << arr[0] << '\n';
		return 0;
	}
	else {
		a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
		b = arr[1] - (arr[0] * a);
		if ((a != (int)a) || (b != (int)b)) {
			cout << 'B'; return 0;
		}
		// (i0, i1) (i1, i2)
		for (int i = 0; i < N - 1; i++) {
			if (arr[i + 1] != ((arr[i] * (int)a) + (int)b)) {
				cout << 'B'; return 0;
			}
		}
		cout << (int)a * arr[N - 1] + (int)b;
	}
	return 0;
}