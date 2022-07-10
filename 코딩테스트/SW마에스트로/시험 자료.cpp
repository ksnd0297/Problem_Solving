#include <iostream>
#include <vector>

using namespace std;

bool check[100001];

vector<int> ve[100001];

int answer[100001];

int dfs(int x, int ret,int depth) {
	if (ve[x].size() == 0) return 0;
	check[x] = true;

	for (int i = 0; i < (int)ve[x].size(); i++) {
		if (!check[ve[x][i]]) {
			return dfs(ve[x][i], ret + answer[ve[x][i]], depth + 1);
		}
	}
	return ret / depth;
}

int main(void) {
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		answer[a] = b;
	}

	for (int i = 0; i < K; i++) {
		int a, b; cin >> a >> b;
		ve[a].push_back(b);
		ve[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		if (!check[i] && answer[i] == 0) {
			answer[i] = dfs(i, 0, 0);
		}
	}
	
	double ans = 0;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		ans += answer[i];
		if (answer[i] != 0) cnt++;
	}
	cout.precision(2);
	cout << fixed;
	cout << ans / cnt;

	return 0;
}