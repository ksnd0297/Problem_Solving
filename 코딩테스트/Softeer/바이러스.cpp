#include <iostream>

using namespace std;

unsigned long long int K, P, N;

int main(void)
{
	cin >> K >> P >> N;

	for (int i = 0; i < N; i++) {
		K = (K * P) % 1000000007;
	}
	cout << K;
	return 0;
}