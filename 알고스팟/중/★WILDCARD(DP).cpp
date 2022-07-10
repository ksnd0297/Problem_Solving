#include <iostream>
#include <string.h>

#define INF 1000000009

using namespace std;

int T;
int N;
long long int cache[100001][4];

long long int dp(int N, int tmp) {
	if (N == 0) return 1;
	if (N < 0) return 0;
	long long int& ret = cache[N][tmp];
	if (ret != -1) return ret;

	if (tmp == 1) {
		ret = (dp(N - 2, 2) + dp(N - 3, 3)) % INF;
	}
	else if (tmp == 2) {
		ret = (dp(N - 1, 1) + dp(N - 3, 3)) % INF;
	}
	else if (tmp == 3) {
		ret = (dp(N - 1, 1) + dp(N - 2, 2)) % INF;
	}
	return ret % INF;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	memset(cache, -1, sizeof(cache));
	while (T--)
	{
		cin >> N;
		cout << (dp(N - 1, 1) + dp(N - 2, 2) + dp(N - 3, 3)) % INF << '\n';
	}
	return 0;
}