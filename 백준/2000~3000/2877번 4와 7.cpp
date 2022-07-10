#include <bits/stdc++.h>

using namespace std;

int N;
string ans;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	while (N != 0) {
		if (N % 2 == 0) {ans += '7'; N = (N - 2) / 2; }
		else { ans += '4'; N = (N - 1) / 2; }
	}

	reverse(ans.begin(), ans.end());
	cout << ans;

	return 0;
}