#include <iostream>
#include <vector>

using namespace std;

vector<int> Node[1002];
bool check[1002];

int N, M, V;



int main(void)
{
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int A, B; cin >> A >> B;
		Node[A].push_back(B);
	}
	DFS(V);
	memset(check, 0, sizeof(check));
	BFS(V);

	return 0;
}