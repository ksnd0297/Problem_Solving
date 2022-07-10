#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll M;
ll Q, N;

ll Sum;
ll Xor;

vector<ll> ve;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> M;
	for (ll i = 0; i < M; i++) {
		cin >> Q;
		if (Q == 1) {
			cin >> N; Sum += N;
			Xor ^= N;
		}
		else if (Q == 2) {
			cin >> N; Sum -= N;
			Xor ^= N;
		}
		else if (Q == 3) {
			cout << Sum << '\n';
		}
		else if (Q == 4) {
			cout << Xor << '\n';
		}
	}
	return 0;
}