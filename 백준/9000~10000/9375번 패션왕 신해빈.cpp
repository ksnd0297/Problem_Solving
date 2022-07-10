#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;

		string name, kind;
		map<string, int> m;
		for (int i = 0; i < N; i++) {
			cin >> name >> kind;
			if (m.find(kind) == m.end()) {
				m.insert({ kind,1 });
			}
			else m[kind]++;
		}

		int ans = 1;
		for (auto i : m) {
			ans *= (i.second + 1);
		}
		cout << ans - 1 << '\n';
		m.clear();
	}
	return 0;
}