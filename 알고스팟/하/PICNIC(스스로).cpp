#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int arr[11];
bool fri[11][11];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int C; cin >> C;
	while (C--) {

		vector<pair<int, int>> ve;
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; i++) arr[i-1] = i;
		for (int i = 0; i < m; i++) { // Â¦ ³Ö±â
			int a, b; cin >> a >> b;
			fri[a][b] = true; fri[b][a] = true;
		}
		int ans = 0;
		do {
			bool flag = false;
			for (int i = 0; !flag && i < n; i += 2) {
				if (fri[arr[i]][arr[i + 1]]) flag = true;
			}
			if (!flag)ans++;
		} while (next_permutation(arr, arr + n));
		cout << ans << '\n';
		ve.clear();
		memset(fri, false, sizeof(fri));
	}
	return 0;
}