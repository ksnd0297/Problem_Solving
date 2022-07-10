#include <iostream>

using namespace std;

int main(void)
{
	int N; cin >> N;
	int ans = 0;
	while (N >= 5) {
		N -= 5;
		ans++;
	}
	if (N > 0) ans++;
	cout << ans;
	return 0;
}