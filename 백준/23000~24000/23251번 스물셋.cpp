#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		cout << N * 23 << '\n';
	}
	return 0;
}