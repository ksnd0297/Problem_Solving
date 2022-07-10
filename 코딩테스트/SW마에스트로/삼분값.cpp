#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	vector<int> ans;
	
	int a, b; cin >> a >> b;
	ans.push_back(a);
	ans.push_back(b);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y, z; cin >> x >> y >> z;
		ans.push_back(x);
		ans.push_back(y);
		ans.push_back(z);
		sort(ans.begin(), ans.end());
		cout << ans[ans.size() / 3] << ' ' << ans[(ans.size() * 2) / 3] << '\n';
	}

	return 0;
}