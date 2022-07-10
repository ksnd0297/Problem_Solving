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
	if (a < b) Set[b] = a;
	else Set[a] = b;
}

bool find(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return 1;
	else return 0;
}

class Edge {
public:
	int node[2];
	double distance;
	Edge(int a, int b, double distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	bool operator < (Edge& edge) {
		return this->distance < edge.distance;
	}
};

int N, M;
vector<pair<int, int>> gods;
vector<Edge> edge;

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int X, Y; cin >> X >> Y;
		gods.push_back({ X, Y });
	}

	for (int i = 1; i <= N; i++) ::Set[i] = i;

	for (int i = 0; i < M; i++) {
		int A, B; cin >> A >> B;
		unionParent(A, B);
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			auto A = gods[i];
			auto B = gods[j];
			double distance = sqrt(pow(B.first - A.first, 2) + pow(B.second - A.second, 2));
			edge.push_back(Edge(i + 1,j + 1,distance));

		}
	}
	sort(edge.begin(), edge.end());

	double ans = 0;
	for (int i = 0; i < edge.size(); i++) {
		if (!find(edge[i].node[0], edge[i].node[1])) {
			ans += edge[i].distance;
			unionParent(edge[i].node[0], edge[i].node[1]);
		}
	}

	cout.precision(2);
	cout << fixed << ans;

	return 0;
}