#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;
	while (T--) {
		int goal; cin >> goal;
		int sum = 0;
		bool flag = true;
		for (int i = 0; i < 9; i++) {
			int num; cin >> num;
			sum += num;
			if (sum > goal) { flag = false; }
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}