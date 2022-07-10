#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N; cin >> N;

	vector<pair<int, int>> vec(N);
	vector<int> ans(N);

	for (int i = 0; i < N; i++) {
		cin >> vec[i].first;
		vec[i].second = i;
	}

	sort(vec.begin(), vec.end());

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		ans[vec[i].second] = cnt;
		while (vec[i].first == vec[i + 1].first) {
			ans[vec[i + 1].second] = cnt; i++;
			if (i >= N-1) break;
		}
		cnt++;
	}

	for (int i = 0; i < N; i++) cout << ans[i] << ' ';
}