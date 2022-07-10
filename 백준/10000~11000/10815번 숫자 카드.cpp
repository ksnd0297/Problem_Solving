#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int N;
unordered_map<int, int> um;
int M;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		um.insert({ num, i });
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		bool flag = false;
		int num; cin >> num;
		if (um.find(num) != um.end()) {
			flag = true;
		}
		if (flag) cout << 1 << ' ';
		else cout << 0 << ' ';
	}

	return 0;
}