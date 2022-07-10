#include <bits/stdc++.h>
using namespace std;

int T;

int main(void) {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int x, y; cin >> x >> y;
		cout << "Scenario #" + i + ':' << '\n';
		unsigned long long int ans = (((y - x) + 1) * (x + y)) / 2;
		cout << ans << '\n' << '\n';
	}
}