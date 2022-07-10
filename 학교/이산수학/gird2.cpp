#include <iostream>

using namespace std;

int T;
int ans, garo, sero;

int func(int N, int M, int t, int s, int k, int L) {
	bool flag1 = false;
	bool flag2 = false;
	bool flag3 = false;
	bool flag4 = false;
	bool lastGaro = false, lastSero = false;

	switch (s) {
	case 1: {
		ans = 1;
		garo = 1; sero = 1;
		flag1 = true;
		break;
	}
	case 2: {
		ans = M;
		garo = -1; sero = 1;
		flag2 = true;
		break;
	}
	case 3: {
		ans = N * M;
		garo = -1; sero = -1;
		flag3 = true;
		break;
	}
	case 4: {

		ans = M * (N - 1) + 1;
		garo = 1; sero = -1;
		flag4 = true;
		break;
	}
	}
	if ((t == 3 && (flag1 || flag3)) || (t == 4 && (flag2 || flag4))) {
		bool firstTime = false;
		N--; M--;
		while (1) {
			if (N <= 0 && M <= 0) break;
			if (k >= M) { // 가로
				k -= M;
				ans += M * garo;
				garo *= -1;
				if (firstTime)M--;
				firstTime = true;
			}
			else if (k < M) {
				lastGaro = true; break;
			}

			if (k >= N) { // 세로
				k -= N;
				ans += (N * sero * L);
				sero *= -1;
				N--;
			}
			else if (k < N) {
				lastSero = true; break;
			}
		}
		if (lastGaro) ans += k * garo;
		else if (lastSero) ans += k * sero * L;
	}
	else if ((t == 3 && (flag2 || flag4)) || (t == 4 && (flag1 || flag3))) {
		bool firstTime = false;
		N--; M--;
		while (1) {
			if (N <= 0 && M <= 0) break;
			if (k >= N) { // 세로
				k -= N;
				ans += (N * sero * L);
				sero *= -1;
				if (firstTime)N--;
				firstTime = true;
			}
			else if (k < N) {
				lastSero = true; break;
			}

			if (k >= M) { // 가로
				k -= M;
				ans += M * garo;
				garo *= -1;
				M--;
			}
			else if (k < M) {
				lastGaro = true; break;
			}
		}
		if (lastGaro) ans += k * garo;
		else if (lastSero) ans += k * sero * L;
	}

	return ans;
}

int main(void)
{
	freopen("grid2.inp", "r", stdin);
	freopen("grid2.out", "w", stdout);

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--) {
		int N, M, t, s, k;
		cin >> N >> M >> t >> s >> k;

		cout << func(N, M, t, s, k - 1, M) << '\n';
	}

	return 0;
}