#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> metal; // P : 무게당 가격 , M : 금속의 무게

int W, N;

bool compare(pair<int, int>& a, pair<int, int>& b) {
	if (a.first > b.first) return true;
	return false;
}

int main(void)
{
	cin >> W >> N;
	for (int i = 0; i < N; i++) {
		int M, P; cin >> M >> P;
		metal.push_back(make_pair(P, M));
	}

	sort(metal.begin(), metal.end(), compare);

	int ans = 0;
	for (int i = 0; i < metal.size(); i++) {
		if (W - metal[i].second >= 0) {
			ans += metal[i].first * metal[i].second;
			W -= metal[i].second;
		}
		else {
			ans += metal[i].first * W;
			break;
		}
	}
	cout << ans;
	return 0;
}