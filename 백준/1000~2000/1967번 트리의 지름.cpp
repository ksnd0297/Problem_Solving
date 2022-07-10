#include <bits/stdc++.h>

using namespace std;

int N;

vector<pair<int, int>> node[10001];

vector<int> arr[10001];

int dfs(int index, int dist) {
	if (node[index].size() == 0) return dist;

	int ret = 0;
	for (int i = 0; i < node[index].size(); i++) {
		ret = max(ret,dfs(node[index][i].first, dist + node[index][i].second));
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int A, B, dist;
		cin >> A >> B >> dist;

		node[A].push_back({ B, dist });
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < node[i].size(); j++) {
			arr[i].push_back(dfs(node[i][j].first, node[i][j].second));
		}
	}
	
	for (int i = 1; i <= N; i++) {
		sort(arr[i].begin(), arr[i].end(), greater<int>());
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (arr[i].size() == 1) ans = max(ans, arr[i][0]);
		if (arr[i].size() >= 2) ans = max(ans, arr[i][0] + arr[i][1]);
	}
	cout << ans;

	return 0;
}