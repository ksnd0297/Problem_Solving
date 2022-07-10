#include <bits/stdc++.h>

using namespace std;

int K;
int V, E;

vector<int> Node[20001];
int num[20001];

void BFS(int N) {
	queue<int> q;
	num[N] = 1; q.push(N);
	while (!q.empty()) {
		int N = q.front(); q.pop();

		for (int i = 0; i < Node[N].size(); i++) {
			if (!num[Node[N][i]]) {
				num[Node[N][i]] = num[N] * -1;
				q.push(Node[N][i]);
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> K;
	while (K--) {
		int V, E; cin >> V >> E;
		for (int i = 0; i < E; i++) {
			int From, To; cin >> From >> To;
			Node[From].push_back(To);
			Node[To].push_back(From);
		}

		for (int i = 1; i <= V; i++) if (num[i] == 0) BFS(i);
		

		bool ans = true;
		for (int i = 1; ans && i <= V; i++) {
			for (int j = 0; j < Node[i].size(); j++) {
				if (num[i] == num[Node[i][j]]) ans = false;
			}
		}
		if (ans) cout << "YES" << '\n';
		else cout << "NO" << '\n';

		for (int i = 1; i <= V; i++) Node[i].clear();
		memset(num, 0, sizeof(num));
	}
	return 0;
}