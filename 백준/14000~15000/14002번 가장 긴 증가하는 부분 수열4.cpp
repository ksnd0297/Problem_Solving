#include <bits/stdc++.h>

using namespace std;

int dp[1001];
int path[1001];

int N;
vector<int> A;

int lis(int start) {
	int& ret = dp[start];
	
	if (ret != -1) return ret;

	ret = 1;
	for (int next = start + 1; next < N; next++) {
		if (A[start] < A[next]) {
			int Temp = lis(next) + 1;
			if (ret < Temp) {
				ret = Temp;
				path[start] = next;
			}
		}
	}
	return ret;
}

void ans(int start) {
	if (path[start] == 0) {
		return;
	}
	cout << A[path[start]] << ' ';

	ans(path[start]);

}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int Num; cin >> Num;
		A.push_back(Num);
	}

	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N; i++) {
		if (dp[i] == -1) lis(i);
	}

	int Max = 0;
	int MaxIdx = 0;
	for (int i = 0; i < N; i++) {
		if (Max < dp[i]) {
			Max = dp[i]; MaxIdx = i;
		}
	}

	cout << Max << '\n';
	cout << A[MaxIdx] << ' ';
	ans(MaxIdx);

	return 0;
}