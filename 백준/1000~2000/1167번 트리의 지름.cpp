#include <bits/stdc++.h>

using namespace std;

int V;
bool check[100001];
vector<vector<int, int>> Node[100001];

int main(void) {
	cin >> V;
	for (int i = 1; i <= V; i++) {
		int From; cin >> From;
		while (1) {
			int To; cin >> To;
			if (To == -1) break;
			int cost; cin >> cost;
			Node[From].push_back({ To, cost });
		}
	}

	return 0;
}