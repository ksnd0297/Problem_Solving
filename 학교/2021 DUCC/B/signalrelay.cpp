#include <fstream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int T;
int n, k;
int a, b;

vector<int> arr[1001];
bool check[1001];

void bfs(int x) {
	check[x] = true;

	for (int i = 0; i < arr[x].size(); i++) {
		if (!check[arr[x][i]]) {
			bfs(arr[x][i]);
		}
	}
}

int main(void)
{
	ifstream fin("signalrelay.inp");
	ofstream fout("signalrelay.out");

	fin >> T;
	while (T--) {
		memset(check, 0, sizeof(check));
		fin >> n >> k;
		for (int i = 0; i < k; i++) {
			fin >> a >> b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		for (int i = 1; i <= n; i++) sort(arr[i].begin(), arr[i].end());

		bfs(1);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (!check[i]) ans++;
			arr[i].clear();
		}
		fout << ans << '\n';
	}
	return 0;
}