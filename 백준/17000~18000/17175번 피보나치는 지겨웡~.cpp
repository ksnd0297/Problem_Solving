#include <iostream>
#define mod 1000000007

using namespace std;

int arr[51];

int main(void)
{
	int n; cin >> n;
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 3;
	for (int i = 3; i <= 50; i++) {
		arr[i] = ((arr[i - 1]+1) % mod + arr[i - 2] % mod) %mod;
	}
	cout << arr[n];
	return 0;
}
