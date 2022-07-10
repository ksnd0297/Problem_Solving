#include <bits/stdc++.h>
#define ull long long int

using namespace std;

ull gcd(ull a, ull b) {
	return (b != 0) ? gcd(b, a % b) : a;
}

ull N, S;
ull A;

int main(void) {
	cin >> N >> S;

	cin >> A;
	ull ans = abs(S - A);

	for (int i = 0; i < N - 1; i++) {
		cin >> A;
		ans = gcd(ans, abs(S - A));
	}
	cout << ans;

	return 0;
}