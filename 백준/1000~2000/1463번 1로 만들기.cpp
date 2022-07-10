#include <iostream>
#include <string.h>

using namespace std;

int arr[1000001];

int main(void)
{
	memset(arr, 123456789, sizeof(arr));
	int N; cin >> N;
	arr[1] = 0;
	for (int i = 1; i <= N; i++) {
		if (i * 2 < 1000001 && arr[i * 2] > arr[i] + 1) arr[i * 2] = arr[i] + 1;
		if (i * 3 < 1000001 && arr[i * 3] > arr[i] + 1) arr[i * 3] = arr[i] + 1;
		if (i + 1 < 1000001 && arr[i + 1] > arr[i] + 1) arr[i + 1] = arr[i] + 1;
	}
	cout << arr[N];
	return 0;
}