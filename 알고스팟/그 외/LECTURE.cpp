#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int C; cin >> C;
	while (C--) {
		vector<pair<char, char>> ve;
		string qus; cin >> qus;
		for (int i = 0; i < qus.size(); i += 2) {
			ve.push_back({ qus[i],qus[i + 1] });
		}
		sort(ve.begin(), ve.end());
		for (int i = 0; i < ve.size(); i++) {
			cout << ve[i].first << ve[i].second;
		}
		cout << '\n';
	}
	return 0;
}