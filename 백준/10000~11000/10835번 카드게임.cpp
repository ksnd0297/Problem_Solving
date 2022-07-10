#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int dp[2001][2001];
int A[2001];
int B[2001];

int N;

int func(int leftIdx, int rightIdx) {
	if (leftIdx > N || rightIdx > N) return 0;
	int& ret = dp[leftIdx][rightIdx];
	if (ret != -1) return ret;
	if (B[rightIdx] < A[leftIdx]) {
		ret = func(leftIdx, rightIdx + 1) + B[rightIdx];
	}
	else {
		ret = max(func(leftIdx + 1, rightIdx), func(leftIdx + 1, rightIdx + 1));
	}
	return ret;
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];
	memset(dp, -1, sizeof(dp));
	cout << func(0, 0);

	return 0;
}