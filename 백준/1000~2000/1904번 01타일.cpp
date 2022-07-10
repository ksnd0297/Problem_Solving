#include <iostream>

using namespace std;

int arr[1000001];

int main(void)
{
	arr[1] = 1;
	arr[2] = 2;
	int N; cin >> N;
	for (int i = 3; i <= N; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
	}
	cout << arr[N];
	return 0;
}
