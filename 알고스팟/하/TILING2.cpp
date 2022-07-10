#include <iostream>
#include <cstring>

using namespace std;

int N;
long long int dp[101];

long long int tile(int i) {
	if (i >= N) return 1;
	long long int& ret = dp[i];
	if (ret != -1) return ret;
	
	return ret = (tile(i + 1) + tile(i + 2))% 1000000007;
}

int main() {
	int C; cin >> C;
	while (C--) {
		cin >> N;
		memset(dp, -1, sizeof(dp));
		cout << tile(1) << '\n';
	}

	return 0;
}