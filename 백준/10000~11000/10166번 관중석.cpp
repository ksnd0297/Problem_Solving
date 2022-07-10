#include <bits/stdc++.h>

using namespace std;

int D1, D2;
bool check[2010][2010];

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> D1 >> D2;


	int ans = 0;
	for (int i = D1; i <= D2; i++) {
		int sum = 0;

		for (int j = 1; j <= i; j++) {
			int Num = gcd(i, j);
			check[i / Num][j / Num] = true;
		}
	}
	
	for (int i = 0; i < 2010; i++) {
		for (int j = 0; j < 2010; j++){
			if (check[i][j]) ans++;
		}
	}
	cout << ans;

	return 0;
}