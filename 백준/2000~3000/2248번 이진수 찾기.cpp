#include <iostream>
#include <string>

using namespace std;

int dp[32][32];
string ans;

int main(void)
{
	dp[0][0] = 1;
	dp[1][0] = 1; dp[1][1] = 1;
	for (int i = 2; i <= 31; i++) {
		dp[i][0] = 1; dp[i][i] = 1;
		for (int j = 1; j <= i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
		
	int N, L, I; cin >> N >> L >> I;
	long long int sum = 1;
	long long int pos = 0;
	if (I == 1) {
		for (int i = 0; i < N; i++) ans += '0';
		cout << ans;
		return 0;
	}
	bool flag = false;
	while (N > 0 && pos != I) {
		if (N == 1 && I - pos == 1) { N--; ans += '1'; break; }
		for (int i = 0; i <= L; i++) sum += dp[N - 1][i];
		if (pos + sum <= I) {
			flag = true;
			ans += '1';
			pos += sum;  N--; L--;
			sum = 0;
		}
		else {
			ans += '0';
			N--;
			if (!flag) sum = 1;
			else sum = 0;
		}
	}
	for (int i = 0; i < N; i++) ans += '0';
	cout << ans;

	return 0;
}