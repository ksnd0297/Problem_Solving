#include <bits/stdc++.h>
using namespace std;

int Set[1001];

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

	bool operator < (const Edge& edge) {
		return this->distance < edge.distance;
	}
};

int N;
int M;

vector<Edge> network;

int main(void) {
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b, dis; cin >> a >> b >> dis;
		network.push_back(Edge(a, b, dis));
	}
	sort(network.begin(), network.end());

	for (int i = 1; i <= N; i++) Set[i] = i;

	int ans = 0;
	for (int i = 0; i < network.size(); i++) {
		if (!find(network[i].node[0], network[i].node[1])) {
			ans += network[i].distance;
			unionParent(network[i].node[0], network[i].node[1]);
		}
	}

	cout << ans;
	return 0;
}