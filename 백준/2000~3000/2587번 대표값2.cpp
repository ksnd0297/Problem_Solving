#include <iostream>
#include <algorithm>

using namespace std;

int arr[5];

int main(void)
{
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	cout << sum / 5 << '\n';
	cout << arr[2] << '\n';
	return 0;
}