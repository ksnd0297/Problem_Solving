#include <iostream>

using namespace std;

int main(void)
{
	int E = 1, S = 1, M = 1;
	int ans = 1;

	int A, B, C; cin >> A >> B >> C;
	while (1)
	{
		if (A == E && B == S && C == M) break;
		E++; S++; M++; ans++;
		if (E == 16) E = 1;
		if (S == 29) S = 1;
		if (M == 20) M = 1;
	}
	cout << ans;
	return 0;
}