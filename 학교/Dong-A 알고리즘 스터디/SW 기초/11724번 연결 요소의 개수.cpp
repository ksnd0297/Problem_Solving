#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> Node[1001];
bool check[1001];

void DFS(int N) {
	check[N] = true;

	for (int i = 0; i < Node[N].size(); i++) {
		if (!check[Node[N][i]]) DFS(Node[N][i]);
	}
}

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int From, To; cin >> From >> To;
		Node[From].push_back(To);
		Node[To].push_back(From);
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (!check[i]) {
			DFS(i); ans++;
		}
	}

	cout << ans;

	return 0;
}