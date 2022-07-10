#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;
	while (T--) {
		int cnt = 0;
		int a = 0, b = 0;
		int N, M, x, y; cin >> N >> M >> x >> y; // 10 12 3 9
		bool flag = false;
		if (N >= M) {
			a = x; b = x; cnt = x;
			if (b > M) b %= M; if (b == 0) b += M;
			while (b != y) {
				b += N; cnt += N;
				if (b > M) b %= M; if (b == 0) b += M;
				if (cnt > N * M) { flag = true; break; }
			}
		}
		else if (N < M) {
			a = y; b = y; cnt = y;
			if (a > N) a %= N; if (a == 0) a += N;
			while (a != x) {
				a += M; cnt += M;
				if (a > N) a %= N; if (a == 0) a += N;
				if (cnt > N * M) { flag = true; break; }
			}
		}
		if (flag) cout << -1 << '\n';
		else cout << cnt << '\n';
	}
	return 0;
}