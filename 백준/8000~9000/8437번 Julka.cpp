#include <iostream>

using namespace std;

int main(void)
{
	int P, K; cin >> P >> K;
	int N = ((P - K) / 2);
	cout << N + K << '\n';
	cout << N << '\n';
	return 0;
}