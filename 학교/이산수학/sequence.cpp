#include <iostream>
#pragma warning(disable : 4996)
#define lld unsigned long long int

using namespace std;

int N, L;

lld func(lld N, lld L, lld ret) {
	if (N == 1) return ret;
	if (N > L) return ret - 1;

	if (N % 2 == 0) return func(N / 2, L, ret + 1);
	else if (N % 2 != 0) return func(3 * N + 1, L, ret + 1);
}

int main(void)
{
	//freopen("sequence.inp", "r", stdin);
	//freopen("sequence.out", "w", stdout);

	int index = 1;
	while (1) {
		cin >> N >> L;
		if (N == -1 && L == -1) break;
		lld term = func(N, L, 1);
		cout << "Case " << index << ": " << "A = " << N << ", limit = " << L << ", number of terms = " << term << '\n';
		index++;
	}
	return 0;
}