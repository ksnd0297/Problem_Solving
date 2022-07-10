#include <iostream>

using namespace std;

int T;
int N;

int func(int num) {
	if (num == N) return 1; // 하나의 경우의 수 충족
	if (num > N) return 0; // 경우의수를 충족할수 없기 때문

	if (num < N) {
		return func(num + 1) + func(num + 2) + func(num + 3);
	}
}

int main(void) {
	cin >> T;
	while (T--) {
		cin >> N;
		cout << func(0) << '\n';
	}

	return 0;
}