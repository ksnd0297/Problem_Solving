#include <bits/stdc++.h>

using namespace std;

int N, L;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> L;

	bool flag = false;
	for (int i = L; !flag && i <= 100; i++) {
		int sum = (i * (i - 1)) / 2;
		if (sum > N) break;
		if ((N - sum) % i == 0) {
			flag = true;
			int X = (N - sum) / i;
			for (int k = 0; k < i; k++) cout << X + k << ' ';
		}
	}
	if (!flag) cout << -1;

	return 0;
}