#include <iostream>

using namespace std;

int N;
int a[46];
int b[46];

int main() {
	cin >> N;
	a[0] = 1; b[0] = 0;
	a[1] = 0; b[1] = 1;
	for (int i = 2; i <= N; i++) {
		a[i] = a[i - 1] + a[i - 2];
		b[i] = b[i - 1] + b[i - 2];
	}
	cout << a[N] << ' ' << b[N];
	return 0;
}