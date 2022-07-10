#include <iostream>

using namespace std;

long long int arr[120];

int main(void)
{
	arr[0] = 1; arr[1] = 1; arr[2] = 1;
	for (int i = 3; i < 120; i++) {
		arr[i] = arr[i - 1] + arr[i - 3];
	}
	int N; cin >> N;
	cout << (long long int)arr[N-1];
	return 0;
}