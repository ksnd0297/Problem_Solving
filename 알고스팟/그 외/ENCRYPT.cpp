#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;
	while (T--) {
		string qus; cin >> qus;
		for (int i = 0; i < (int)qus.size(); i += 2) cout << qus[i];
		for (int i = 1; i < (int)qus.size(); i += 2) cout << qus[i];
		cout << '\n';
	}
	return 0;
}