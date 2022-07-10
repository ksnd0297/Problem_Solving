#include <iostream>

using namespace std;

int N;

int main(void)
{
	cin >> N;
	
	int ans = 0;

	if (N % 5 == 0) cout << N / 5;
	else {
		while (1) {
			N -= 3; ans++;
			if (N < 3) {
				cout << -1;
				return 0;
			}

			if (N % 5 == 0) {
				cout << ans + N / 5;
				return 0;
			}
		}
	}
	
	return 0;
}