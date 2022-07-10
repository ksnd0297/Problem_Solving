#include <iostream>
#include <vector>
using namespace std;

// 그래프의 인접 리스트 표현
vector<vector<int>> adj;
// 각 정점을 방문했는지 여부를 나타낸다.
vector<bool> visited;
// 깊이 우선 탐색을 구현한다.
void dfs(int here) {
	cout << "DFS visits " << here << endl;
	visited[here] = true;
	// 모든 인접 정점을 순회하면서
	for (int i = 0; i < adj[here].size(); ++i) {
		int there = adj[here][i];
		// 아직 방문한 적 없다면 방문한다.
		if (!visited[there])
			dfs(there);
	}
	// 더이상 방문할 정점이 없으니, 재귀 호출을 종료하고 이전 정점으로 돌아간다.
}

// 모든 정점을 방문한다.
void dfsAll() {
	//visited를 모두 false로 초기화한다.
	visited = vector<bool>(adj.size(), false);
	// 모든 정점을 순회하면서, 아직 방문한 적 없으면 방문한다.
	for (int i = 0; i < adj.size(); ++i)
		if (!visited[i])
			dfs(i);
} 