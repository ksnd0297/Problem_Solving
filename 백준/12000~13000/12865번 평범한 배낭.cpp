#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> object;
int N, K;

long long int dp[101][100001];

int main(void) {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int W, V; cin >> W >> V;
		object.push_back(make_pair(W, V));
	}

	long long  int max = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			if (j - object[i - 1].first >= 0) {
				if (dp[i - 1][j] < dp[i - 1][j - object[i - 1].first] + object[i - 1].second) dp[i][j] = dp[i - 1][j - object[i - 1].first] + object[i - 1].second;
				else if (dp[i - 1][j] < object[i - 1].second) dp[i][j] = object[i - 1].second;
				else dp[i][j] = dp[i - 1][j];
			}
			else dp[i][j] = dp[i - 1][j];
			if (max < dp[i][j]) max = dp[i][j];
		}
	}
	cout << max;
	return 0;
}