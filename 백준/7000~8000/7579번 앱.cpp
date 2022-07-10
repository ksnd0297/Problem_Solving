#include <iostream>
#include <vector>

using namespace std;

int dp[101][100001]; // object, cost
vector<pair<int, int>> object(101); // pair<weight, cost>

int N, M;

int main(void)
{
	int K = 0;
	for (int i = 0; i < N; i++) cin >> object[i].first;
	for (int i = 0; i < N; i++) {
		cin >> object[i].second;
		K += object[i].second;
	}

	for (int i = 1; i <= N; i++) {
		for(int j=0;j<=K;j++) {
			)
	}
}