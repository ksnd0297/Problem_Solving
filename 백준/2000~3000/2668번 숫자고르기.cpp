#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int N;

bool Up[101];
bool Down[101];
vector<int> ve[101];

bool check[101];

void Dfs(int n) {
	Up[n] = true;
	Down[ve[n][0]] = true;
	if (!Up[ve[n][0]]) {
		Dfs(ve[n][0]);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int num; cin >> num;
		ve[i].push_back(num);
	}

	vector<int> ans;
	for (int i = 1; i <= N; i++) {
		memset(Up, 0, sizeof(Up));
		memset(Down, 0, sizeof(Down));
		if (!check[i]) {
			Dfs(i);

			bool flag = false;
			for (int i = 1; !flag && i <= N; i++) {
				if (Up[i] != Down[i]) flag = true;
			}
			if (!flag) {
				for (int i = 1; i <= N; i++) {
					if (Up[i] && Down[i]) {
						ans.push_back(i);
						check[i] = true;
					}
				}
			}
		}
	}
	sort(ans.begin(), ans.end());
	
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}