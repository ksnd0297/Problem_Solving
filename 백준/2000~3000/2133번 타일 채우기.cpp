#include <iostream>
#include <cstring>

using namespace std;

long long int dp[31];

long long int tiling(int N) {
	if (N % 2 != 0) return 0;
	if (N == 2) return 3;
	long long int& ret = dp[N];
	if (ret != -1) return ret;
	ret = 3 * (tiling(N - 2));
	for (int i = N - 4; i >= 2; i -= 2) {
		ret += 2 * (tiling(i));
	}
	ret += 2;
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	int N; cin >> N;
	cout << tiling(N);
	return 0;
}