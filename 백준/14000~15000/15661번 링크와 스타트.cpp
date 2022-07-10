#include <iostream>
#include <cmath>
#include <vector>
#define INF 987654321

using namespace std;

int N;
int arr[21][21];

int func(int index, vector<int>& startTeam, vector<int>& linkTeam) {
	int ans = INF;
	if (index == N) {
		if (startTeam.size() == 0 || linkTeam.size() == 0) return INF;

		int start = 0, link = 0;
		for (int i = 0; i < startTeam.size(); i++) {
			for (int j = i + 1; j < startTeam.size(); j++) {
				start += (arr[startTeam[i]][startTeam[j]] + arr[startTeam[j]][startTeam[i]]);
			}
		}

		for (int i = 0; i < linkTeam.size(); i++) {
			for (int j = i + 1; j < linkTeam.size(); j++) {
				link += (arr[linkTeam[i]][linkTeam[j]] + arr[linkTeam[j]][linkTeam[i]]);
			}
		}

		return abs(start - link);
	}

	startTeam.push_back(index);
	ans = min(ans, func(index + 1, startTeam, linkTeam));
	startTeam.pop_back();

	linkTeam.push_back(index);
	ans = min(ans, func(index + 1, startTeam, linkTeam));
	linkTeam.pop_back();

	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	vector<int> startTeam;
	vector<int> linkTeam;
	cout << func(0, startTeam, linkTeam);

	return 0;
}