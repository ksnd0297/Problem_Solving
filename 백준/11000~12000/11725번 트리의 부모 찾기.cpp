#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> node[100001];
bool check[100001];
int parent[100001];

void BFS(int N) {
	queue<int> q;
	q.push(N);
	check[N] = true;
	while (!q.empty()) {
		int x = q.front();
		for (int i = 0; i < node[x].size(); i++) {
			if (!check[node[x][i]]) {
				parent[node[x][i]] = x;
				check[node[x][i]] = true;
				q.push(node[x][i]);
			}
		}
		q.pop();
	}
}

int main(void)
{
	int N; cin >> N;
	for (int i = 0; i < N-1; i++) {
		int a, b; cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}

	BFS(1);
	for (int i = 2; i <= N; i++) {
		cout << parent[i] << '\n';
	}
	return 0;
}