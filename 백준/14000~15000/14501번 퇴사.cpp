///* 브루트 포스 */
//#include <iostream>
//
//using namespace std;
//
//int N;
//
//int T[16];
//int P[16];
//
//int func(int day, int money) {
//	if (day > N) return 0;
//	else if (day == N) return money;
//
//	return max(func(day + T[day], money + P[day]), func(day + 1, money));
//}
//
//int main(void)
//{
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> T[i] >> P[i];
//	}
//
//	cout << func(0, 0);
//
//	return 0;
//}
//
///* DP */
//#include <iostream>
//
//using namespace std;
//
//int dp[1500001];
//
//int T[1500001];
//int P[1500001];
//
//int N;
//
//int main(void)
//{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//
//
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> T[i] >> P[i];
//	}
//
//	for (int i = N - 1; i >= 0; i--) {
//		if (i + T[i] > N) dp[i] = dp[i + 1];
//		else dp[i] = max(dp[i + 1], P[i] + dp[i + T[i]]);
//	}
//
//	cout << dp[0];
//
//	return 0;
//}