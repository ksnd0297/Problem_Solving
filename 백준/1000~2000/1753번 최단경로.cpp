#include <iostream>
#define INF 987654321

using namespace std;

int arr[20001][20001];

int dist[20001];
bool visit[20001];

int V, E;
int K;

int getSmallIndex() {
	int min = INF;
	int index = 0;
	for (int i = 1; i <= V; i++) {
		if (dist[i] < min && !visit[i]) {
			min = dist[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start) {
	for (int i = 1; i <= V; i++) {
		dist[i] = arr[start][i];
	}
	visit[start] = true;
	for (int i = 1; i <= V - 1; i++) {
		int current = getSmallIndex();
		visit[current] = true;
		for (int j = 1; j <= V; j++) {
			if (!visit[j]) {
				if (dist[current] + arr[current][j] < dist[j])
					dist[j] = dist[current] + arr[current][j];
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> V >> E;
	cin >> K;
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (i == j) arr[i][j] = 0;
			else arr[i][j] = 987654321;
		}
	}

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		arr[u][v] = min(arr[u][v], w);
	}

	for (int i = 1; i <= V; i++) {
		dist[i] = arr[K][i];
	}

	dijkstra(K);

	for (int i = 1; i <= V; i++) {
		if (i == K) cout << 0 << '\n';
		else {
			if (dist[i] == 0) cout << "INF" << '\n';
			else cout << dist[i] << '\n';
		}
	}

	return 0;
}