#include <iostream>

using namespace std;

int gcd(int A, int B) // Euclidean algorithm
{
	return B == 0 ? A : gcd(B, A % B);
}

int T;
int A, B;

int main(void)
{
	cin >> T;
	while (T--) {
		cin >> A >> B;
		int GCD = gcd(A, B);
		cout << GCD * (A / GCD) * (B / GCD) << '\n';
	}
	return 0;
}