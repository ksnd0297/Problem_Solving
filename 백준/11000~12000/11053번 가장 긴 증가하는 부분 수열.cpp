#include <iostream>
#include <string.h>

using namespace std;

int N;
int arr[1001];
int cache[1001];

int lis(int start) {
	int& ret = cache[start];
	if (ret != -1) return ret;

	ret = 1;
	for (int next = start + 1; next < N; next++) {
		if (arr[start] < arr[next]) ret = max(ret, lis(next) + 1);
	}
	return ret;
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < N; i++) {
		lis(i);
	}
	int max = 0;
	for (int i = 0; i < N; i++) {
		if (max < cache[i]) max = cache[i];
	}
	cout << max;
	return 0;
}