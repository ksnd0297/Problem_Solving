#include <iostream>

using namespace std;

bool sieve[1000001];
int A, B;

int main(void)
{
	sieve[0] = sieve[1] = true;
	for (int i = 2; i * i <= 1000000; i++) {
		if (!sieve[i]) {
			for (int j = i * i; j <= 1000000; j += i) sieve[j] = true;
		}
	}
	cin >> A >> B;
	for (int i = A; i <= B; i++) {
		if (!sieve[i]) cout << i << '\n';
	}

	return 0;
}