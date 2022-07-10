#include <iostream>
#include <algorithm>
#define INF 987654321

using namespace std;

int C;
int N, L;

int arr[1001];

double func(int length) {
	double ret = INF;
	for (int i = 0; i < N; i++) {
		double sum = 0;
		for (int j = i; j < i + length && i + length <= N; j++) sum += arr[j];
		if (sum != 0)ret = min(ret, sum / length);
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> C;
	while (C--) {
		cin >> N >> L;
		for (int i = 0; i < N; i++) cin >> arr[i];

		double ans = INF;
		for (int i = L; i <= N; i++) {
			ans = min(ans, func(i));
		}
		cout.precision(8);
		cout << fixed << ans << '\n';
	}
	return 0;
}