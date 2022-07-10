#include <iostream>

using namespace std;

bool pn[10001];

void sieve() {
	pn[0] = pn[1] = true;
	for (int i = 2; i <= 10000; i++) {
		if (!pn[i]) {
			for (int j = i * i; j <= 10000; j += i) pn[j] = true;
		}
	}
}

int T;

int main(void) {
	sieve();
	cin >> T;
	while (T--) {
		int num; cin >> num;
		int ans = 0;
		for (int i = 2; i <= num / 2; i++) {
			if (!pn[i] && !pn[num - i]) {
				ans = i;
			}
		}
		cout << ans << ' ' << num - ans << '\n';
	}
}