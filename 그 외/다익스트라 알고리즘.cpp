#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

vector<pair<int, int>> ve[20001];

int V, E;
int K; // start

struct compare {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second < b.second;
	}
};

vector<int> dijkstra(int start) {
	vector<int> d(V, INF);
	d[start] = 0;
	priority_queue<pair<int, int >, vector<pair<int, int>>, compare> pq; // cost를 앞에 넣음
	pq.push(make_pair(start, 0));

	while (!pq.empty()) {
		int from = pq.top().first;
		int cost = -pq.top().second;

		pq.pop();

		if (d[from] < cost) continue;

		for (int i = 0; i < ve[from].size(); i++) {
			int next = ve[from][i].first;
			int nextDistance = cost + ve[from][i].second;
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}
	return d;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> V >> E;
	cin >> K;
	for (int i = 0; i < E; i++) {
		int u, v, w; cin >> u >> v >> w;
		ve[u - 1].push_back(make_pair(v - 1, w));
	}

	vector<int> d = dijkstra(K - 1);
	for (int i = 0; i < V; i++) {
		if (d[i] == INF) cout << "INF" << '\n';
		else cout << d[i] << '\n';
	}

	return 0;
}