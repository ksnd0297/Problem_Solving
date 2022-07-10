#include <iostream>

using namespace std;

long long int dp[81];
int N;

long long int fibo(int i) {
	long long int& ret = dp[i];
	if (i == 0) return ret = 1;
	if (i == 1) return ret = 1;
	
	if (ret != 0) return ret;
	return ret = fibo(i-1) + fibo(i-2);
}

int main() {
	cin >> N;
	fibo(N);
	if (N == 1) cout << 4;
	else cout << (dp[N-1] * 2) + ((dp[N-1] + dp[N - 2]) * 2);
	return 0;
}