#include <bits/stdc++.h>

using namespace std;

vector<int> Node[100001];
int check[100001];

int N, M, R;

int depth = 1;

void DFS(int N) {
	check[N] = depth++;

	for (int i = 0; i < Node[N].size(); i++) {
		if (check[Node[N][i]] == 0) DFS(Node[N][i]);
	}

}

int main(void) {
	cin >> N >> M >> R;
	for (int i = 0; i < M; i++) {
		int u, v; cin >> u >> v;
		Node[u].push_back(v);
		Node[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) sort(Node[i].begin(), Node[i].end());
	DFS(R);
	for (int i = 1; i <= N; i++) {
		cout << check[i] << '\n';
	}

	return 0;
}