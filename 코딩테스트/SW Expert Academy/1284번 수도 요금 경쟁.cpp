#include <bits/stdc++.h>

using namespace std;

int T;
int P, Q, R, S, W;

int A, B;

int main(void) {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> P >> Q >> R >> S >> W;
		A = W * P;
		if (W <= R) B = Q;
		else B = Q + (W - R) * S;

		cout << "A" << A << '\n';
		cout << "B" << B << '\n';
	}

	return 0;
}