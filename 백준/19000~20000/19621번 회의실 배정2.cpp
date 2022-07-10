#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int cache[26];
int N;

vector<pair<pair<int, int>, int>> ve;

bool compare(const pair<pair<int, int>, int>& ve1, const pair<pair<int, int>, int>& ve2) {
	return ve1.first.second < ve2.first.second;
}

int dp(int pos) {
	int& ret = cache[pos];
	if (ret != 0) return ret;
	for (int i = pos + 1; i < N; i++) {
		if (ve[pos].first.second <= ve[i].first.first) {
			ret = max(ret, dp(i) + ve[pos].second);
		}
	}
	if (ret == 0) return ret = ve[pos].second;
	else return ret;
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		int A, B, C; cin >> A >> B >> C;
		ve.push_back(make_pair(make_pair(A, B), C));
	}
	sort(ve.begin(), ve.end());
	sort(ve.begin(), ve.end(), compare);
	int max = 0;
	for (int i = 0; i < N; i++) {
		int ans = dp(i);
		if (max < ans) max = ans;
	}
	cout << max;
	return 0;
}