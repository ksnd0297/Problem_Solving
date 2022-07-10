#include <iostream>

using namespace std;

char arr[21][21];
int N;

int main(void)
{
	cin >> N;
	int a = 0;
	int b = N - 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == 0 || i == N - 1) arr[i][j] = '*';
			else if (j == a || j == b || j == 0 || j == N - 1) {
				arr[i][j] = '*';
			}
			else arr[i][j] = ' ';
		}
		a++; b--;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}

	return 0;
}