#include <iostream>
#include <algorithm>

using namespace std;

int money[100001];

int min(int A, int B, int C, int D) {
	int value = 123456789;
	value = min(value, A);
	value = min(value, B);
	value = min(value, C);
	value = min(value, D);
	return value;
}

int main(void)
{
	money[1] = 1;
	money[2] = 1;
	money[3] = 2;
	money[4] = 2;
	money[5] = 1;
	money[6] = 2;
	money[7] = 1;

	for (int i = 8; i <= 100000; i++) {
		money[i] = min(money[i - 1], money[i - 2], money[i - 5], money[i - 7]) + 1;
	}
	int N; cin >> N;
	cout << money[N];
	return 0;
}