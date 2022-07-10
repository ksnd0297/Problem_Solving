#include <iostream>
#pragma warning(disable : 4996)

using namespace std;

int T;
int M;
int start = 0;
int end = 987654321;

void func(int P, int N) {
	int startTemp = 0;
	int endTemp = 0;
	if (N != 1) {
		int A = ((N * N) - (3 * N)) / 2;

		startTemp = (int)ceil(((double)(P - A) / N) - 1);
		endTemp = (int)floor((double)(P - A - 2) / (N - 1));

		if (startTemp >= start) start = startTemp;
		if (endTemp <= ::end) ::end = endTemp;
		return;
	}
	else return;
}

int main(void) {
	freopen("line.inp", "r", stdin);
	freopen("line.out", "w", stdout);

	cin >> T;
	while (T--) {
		cin >> M;
		start = 0; ::end = 987654321;
		bool flag = false;
		for (int i = 1; i <= M; i++) {
			int Q, A;cin >> Q >> A;
			func(Q, A);
			if (!flag && start == ::end) {
				flag = true;
				cout << i << ' ' << start << '\n';
			}
		}
		if (!flag) cout << -1 << '\n';
	}
	return 0;
}