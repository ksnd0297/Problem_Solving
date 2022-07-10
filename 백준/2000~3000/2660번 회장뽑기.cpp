#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <string.h>

using namespace std;

vector<int> node[51];
int check[51]; // 방문 배열
int score[51];

int N;
int A, B;

void BFS(int n)
{
	queue<int> que;
	que.push(n);
	check[n] = 1;
	while (!que.empty()) {
		bool flag = false;
		int top = que.front(); que.pop();
		for (int i = 0; i < node[top].size(); i++) {
			if (!check[node[top][i]]) {
				que.push(node[top][i]);
				check[node[top][i]] = check[top] + 1;
			}
		}
	}
	int max = 0;
	for (int i = 1; i <= N; i++) {
		if (max < check[i]) max = check[i];
	}
	score[n] = max - 1;
}

int main(void)
{
	cin >> N;
	while (1)
	{
		cin >> A >> B;
		if (A == -1 && B == -1) break;
		node[A].push_back(B);
		node[B].push_back(A);
	}

	for (int i = 1; i <= N; i++) {
		memset(check, false, sizeof(check));
		BFS(i);
	}

	int min = 987654321;
	for (int i = 1; i <= N; i++) {
		if (min > score[i]) min = score[i];
	}

	vector<int> ans;
	for (int i = 1; i <= N; i++) {
		if (min == score[i]) ans.push_back(i);
	}
	sort(ans.begin(), ans.end());
	cout << min << ' ' << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		if (i == ans.size() - 1) cout << ans[i];
		else cout << ans[i] << ' ';
	}

	return 0;
}