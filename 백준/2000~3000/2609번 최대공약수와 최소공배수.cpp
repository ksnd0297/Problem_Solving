#include <iostream>

using namespace std;

int gcd(int A, int B) // Euclidean algorithm
{
	return B == 0 ? A : gcd(B, A % B);
}

int main(void)
{
	int A, B;
	cin >> A >> B;

	int GCD = gcd(A, B); 
	int LCM = GCD * (A / GCD) * (B / GCD); // L = Gab -> ( a = A/G , b = B/G ) -> L : 최소공배수, G  : 최대공약수
	cout << GCD << '\n';
	cout << LCM << '\n';

	return 0;
}