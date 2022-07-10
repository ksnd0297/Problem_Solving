#include <iostream>

using namespace std;

long long int mul(int A, int B, int C) {
	if (B == 0) return 1 % C;
	if (B == 1) return A % C;
	if (B % 2 == 0) { // Â¦¼ö
		return (mul(A, B / 2, C) % C * mul(A, B / 2, C) % C) % C;
	}
	else if (B % 2 == 1) { // È¦¼ö
		return (mul(A, B / 2, C) % C * mul(A, B / 2 + 1, C) % C) % C;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int A, B, C; cin >> A >> B >> C;
	cout << mul(A, B, C);
	return 0;
}