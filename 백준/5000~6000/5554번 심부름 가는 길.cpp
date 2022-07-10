#include <iostream>

using namespace std;

int main(void)
{
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		int num; cin >> num;
		ans += num;
	}
	cout << ans / 60 << '\n';
	cout << ans % 60 << '\n';

	return 0;
}