#include <iostream>

using namespace std;

int coin[10];

int main() {
	int N, K; cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> coin[i];

	int ans = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (K == 0) break;
		ans += K / coin[i];
		K %= coin[i];
	}
	cout << ans;
	return 0;
}