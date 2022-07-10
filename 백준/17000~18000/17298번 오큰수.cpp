#include <iostream>
#include <stack>
#include<vector>

using namespace std;

int N;

int ans[1000001];
vector<int> temp;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N; 
	stack<pair<int, int>> s;
	for (int i = 0; i < N; i++) {
		int Num; cin >> Num;
		temp.push_back(Num);
		if (s.empty()) s.push({ Num, i });

		while (!s.empty()) {
			if (s.top().first < Num) {
				ans[s.top().second] = Num;
				s.pop();
			}
			else break;
		}
		if (s.empty() || s.top().first >= Num) {
			s.push({ Num, i });
		}
	}

	while (!s.empty()) {
		ans[s.top().second] = -1;
		s.pop();
	}

	for (int i = 0; i < temp.size(); i++) {
		cout << ans[i] << ' ';
	}

	return 0;
}