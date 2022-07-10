#include <iostream>

using namespace std;

int N;

char arr[201][101];

int main(void)
{
	cin >> N;

	if (N % 2 == 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (j % 2 == 0) cout << '*';
				else cout << ' ';
			}
			cout << '\n';
			for (int j = 0; j < N; j++) {
				if (j % 2 == 0) cout << ' ';
				else cout << '*';
			}
			cout << '\n';
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= N; j++) {
				if (j % 2 == 0) cout << '*';
				else cout << ' ';
			}
			cout << '\n';
			for (int j = 0; j < N; j++) {
				if (j % 2 == 0) cout << ' ';
				else cout << '*';
			}
			cout << '\n';
		}
	}

	return 0;
}