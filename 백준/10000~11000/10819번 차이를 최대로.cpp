#include <iostream>
#include <algorithm>

using namespace std;

int arr[8];

int main(void)
{
	int N; cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	
	int ans = 0;
	sort(arr, arr + N);
	do {
		int max = 0;
		for (int i = 1; i < N; i ++) max += abs(arr[i-1] - arr[i]);
		if (ans < max) ans = max;
	}while(next_permutation(arr, arr+N));

	cout << ans;
	return 0;
}