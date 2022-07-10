#include <bits/stdc++.h>
using namespace std;

int T;
int N, D;

int main(void) {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N >> D;
		cout << "#" << i << ' ';
		cout << ceil(N / (double)(D * 2 + 1)) << '\n';
	}

	return 0;
}