#include <iostream>
#include <string.h>

using namespace std;

long long int ans[31][31];


int main(void) {
	int a, b, c; cin >> a >> b >> c;
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 31; j++) {
			if (j == 0) ans[i][j] = 1;
			else if (j == i) ans[i][j] = 1;
			else ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
		}
	}

	long long int sum = 0;
	for (int i = a - 1; i < a + c - 1; i++) {
		for (int j = b - 1; j <= (b - 1) + i - (a - 1); j++) {
			sum += ans[i][j];
		}
	}
	cout << sum;
	return 0;
}