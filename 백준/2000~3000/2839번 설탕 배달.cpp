#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

long long int N, k;

long long int arr[10];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> N >> k;
	long long int Temp = pow(k, k - 1);
	if (N != 1) N++;
	
	if (N < Temp) N = Temp;
	long long int Limit = pow(k, k);


	while (1) {
		long long int Temp = N;
		if (Temp >= Limit) {
			cout << -1;
			return 0;
		}

		while (N != 0) {
			arr[N % k]++;
			N /= k;
		}

		bool flag = false;
		for (long long int i = 0; !flag && i < k; i++) {
			if (arr[i] == 0) flag = true;
		}
		if (!flag) {
			cout << Temp;
			return 0;
		}
		memset(arr, 0, sizeof(arr));
		N = Temp;
		N++;
	}

	return 0;
}