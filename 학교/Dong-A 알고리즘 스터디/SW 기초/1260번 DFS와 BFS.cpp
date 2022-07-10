#include <bits/stdc++.h>

using namespace std;

int N, M;
int V;

vector<int> Node[1001];
bool check[1001];

void DFS(int N) {
	cout << N << ' ';
	check[N] = true;

	for (int i = 0; i < Node[N].size(); i++) {
		if (!check[Node[N][i]]) DFS(Node[N][i]);
	}
}

void BFS(int N) {
	queue<int> q; 
	q.push(N); check[N] = true;
	while (!q.empty()) {
		int N = q.front(); q.pop();
		cout << N << ' ';
		for (int i = 0; i < Node[N].size(); i++) {
			if (!check[Node[N][i]]) {
				q.push(Node[N][i]);
				check[Node[N][i]] = true;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int From, To; cin >> From >> To;
		Node[From].push_back(To);
		Node[To].push_back(From);
	}

	for (int i = 1; i <= N; i++) sort(Node[i].begin(), Node[i].end());

	DFS(V);
	memset(check, 0, sizeof(check));
	cout << '\n';
	BFS(V);

	return 0;
}