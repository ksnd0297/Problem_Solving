#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <pair<string, string>> ve;

string bsearch(string site) {
	int start=0, end = ve.size();
	while (start <= end) {
		int mid = (start + end) / 2;
		if (site == ve[mid].first) return ve[mid].second;
		if (site < ve[mid].first) {
			end = mid - 1;
		}
		else start = mid + 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M; cin >> N >> M;

	string site;
	string password;
	for (int i = 0; i < N; i++) {
		cin >> site >> password;
		ve.push_back(make_pair(site,password));
	}

	sort(ve.begin(), ve.end());
	for (int i = 0; i < M; i++) {
		cin >> site;
		cout << bsearch(site) << '\n';
	}
}