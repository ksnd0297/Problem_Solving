#include <iostream>

using namespace std;

int main(void)
{
	int T; cin >> T;
	while (T--) {
		int A, B, C; cin >> A >> B >> C;
		if (A == C) {
			if ((A == 0 && C == 0) && B % 2 == 1) {
				cout << "No" << '\n'; continue;
			}
			else {
				cout << "Yes" << '\n'; continue;
			}
		}
		else if (A > C) {
			if ((A - C - 2 * B) % 2 == 0) {
				cout << "Yes" << '\n'; continue;
			}
			else cout << "No" << '\n'; continue;
		}
		else {
			cout << "No" << '\n'; continue;
		}
	}
	return 0;
}