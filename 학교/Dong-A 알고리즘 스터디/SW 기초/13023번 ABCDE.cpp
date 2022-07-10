#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> fri[2001];
bool check[2001];

bool DFS(int N, int depth) {
	if (depth == 5) return true;
	bool ret = false;
	for (int i = 0; !ret && i < fri[N].size(); i++) {
		if (!check[fri[N][i]]) {
			check[fri[N][i]] = true;
			ret = DFS(fri[N][i], depth + 1);
			check[fri[N][i]] = false;
		}
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int From, To; cin >> From >> To;
		fri[From].push_back(To);
		fri[To].push_back(From);
	}


	bool ans = false;
	for (int i = 0; !ans && i < N; i++) {
		check[i] = true;
		if (DFS(i, 1)) ans = true;
		check[i] = false;
	}

	cout << ans;

	return 0;
}