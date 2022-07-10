#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> ve;

bool compare(const pair<int, int>& ve1, const pair<int, int>& ve2) {
	return ve1.second < ve2.second;
}

int main() {
	int N; cin >> N;
	int start, end;
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		ve.push_back(make_pair(start, end));
	}
	sort(ve.begin(), ve.end());
	sort(ve.begin(), ve.end(), compare);

	int count = 1;

	end = ve[0].second;
	for (int i = 1; i < N; i++) {
		if (end <= ve[i].first) {
			end = ve[i].second; count++;
		}
	}

	cout << count;
	return 0;
}