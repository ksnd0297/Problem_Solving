#include <bits/stdc++.h>
using namespace std;

int Set[10001];

int getParent(int x) {
	if (Set[x] == x) return x;
	return Set[x] = getParent(Set[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a > b) Set[a] = Set[b];
	else Set[b] = Set[a];
}

bool find(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return true;
	return false;
}

class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	bool operator < (Edge& edge) {
		return this->distance < edge.distance;
	}
};

vector<Edge> edge;

int V, E;

int main(void) {
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int A, B, C; cin >> A >> B >> C;
		edge.push_back(Edge(A, B, C));
	}

	sort(edge.begin(), edge.end());

	for (int i = 1; i <= V; i++) Set[i] = i; 

	signed long long int ans = 0;
	for (int i = 0; i < edge.size(); i++) {
		if (!find(edge[i].node[0], edge[i].node[1])) {
			ans += edge[i].distance;
			unionParent(edge[i].node[0], edge[i].node[1]);
		}
	}
	cout << ans;

	return 0;
}