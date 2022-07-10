#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<int, int>> city;
vector<pair<int, int>> chicken;

int N, M;

int func(vector<pair<int,int>>& ve, int Count,int index) {
	if (Count == M) {
		int sum = 0;
		for (int i = 0; i < city.size(); i++) {
			int cityY = city[i].first;
			int cityX = city[i].second;
			int len = 987654321;
			for (int j = 0; j < ve.size(); j++) {
				int chickenY = ve[j].first;
				int chickenX = ve[j].second;

				len = min(len, abs(chickenY - cityY) + abs(chickenX - cityX));
			}
			if (len != 987654321) sum += len;
		}
		return sum;
	}

	int ans = 987654321;
	for (int i = index; i < chicken.size(); i++) {
		ve.push_back(chicken[i]);
		ans = min(ans, func(ve, Count + 1, i + 1));
		ve.pop_back();
	}
	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int Num;  cin >> Num;
			if (Num == 1) city.push_back({ i,j });
			if (Num == 2) chicken.push_back({ i, j });
		}
	}

	vector<pair<int, int>> ve;
	cout << func(ve, 0, 0);

	return 0;
}