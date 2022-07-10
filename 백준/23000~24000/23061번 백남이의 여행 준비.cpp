#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int arr[101][1000001];
vector<pair<int, int>> object;
vector<int> pagc;
int N, M;
#define EPSILON 0.00001 //정확도.

bool float_compare(double a, double b)
{
	return fabs(a - b) < EPSILON; // 앞서 정의한 0.00001 이하는 비교하지 않습니다.
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M; // N 물건의 개수 M 가방
	for (int i = 0; i < N; i++) {
		int W, V; cin >> W >> V;
		object.push_back(make_pair(W, V));
	}
	int maxPagc = 0;
	for (int i = 0; i < M; i++) {
		int num; cin >> num;
		pagc.push_back(num);
		maxPagc = num;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= maxPagc; j++) {
			if (object[i - 1].first > j) arr[i][j] = arr[i - 1][j];
			else {
				arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - object[i - 1].first] + object[i - 1].second);
			}
		}

	}

	double ans = -1;
	int idx = -1;

	for (int i = 0; i < M; i++) {
		if (!float_compare(ans, (double)arr[N][pagc[i]] / pagc[i]) && ans < (double)arr[N][pagc[i]] / pagc[i]) {
			ans = (double)arr[N][pagc[i]] / pagc[i];
			idx = i;
		}
	}
	cout << idx + 1;

	return 0;
}