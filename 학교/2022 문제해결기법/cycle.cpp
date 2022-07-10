#include <iostream>
#pragma warning(disable: 4996)
#define ull unsigned long long int

using namespace std;

int N, L;

ull ans[1000001];

ull func(ull N, ull cycle) {
	if (N == 1) return cycle;
	if (N <= 1000000 && ans[N] != 0) return (ans[N] + cycle - 1);

	if (N % 2 == 0) return func(N / 2, cycle + 1);
	else if (N % 2 != 0) return func(3 * N + 1, cycle + 1);
}

int main(void)
{
	freopen("cycle.inp", "r", stdin);
	freopen("cycle.out", "w", stdout);

	for (int i = 1; i <= 1000000; i++) ans[i] = func(i, 1);

	while (cin >> N >> L) {
		ull ret = 0;
		if (N < L) for (int i = N; i <= L; i++) ret = max(ret, ans[i]);
		else for (int i = L; i <= N; i++) ret = max(ret, ans[i]);

		cout  << N << ' ' << L << ' ' << ret << '\n';
	}
	return 0;
}