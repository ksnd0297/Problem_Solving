#include <iostream>

using namespace std;

bool sieve[1000001];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	sieve[1] = true;
	for (int i = 2; i <= 1000000; i++) {
		if (sieve[i] == false) {
			for (int j = i * 2; j <= 1000000; j += i) sieve[j] = true;
		}
	}

	int N;
	while (1) {
		cin >> N;
		if (N == 0) break;
		for (int i = 3; i <= N / 2; i += 2) {
			if (!sieve[i] && !sieve[N - i]) {
				cout << N << " = " << i << " + " << N - i << '\n';
				break;
			}
		}
	}
	return 0;
}