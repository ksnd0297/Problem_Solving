#include <iostream>

using namespace std;

int re(int N) {
	if (N < 0) return 0;
	if (N == 0) return 1;
	return re(N - 3) + re(N - 2) + re(N - 1);
}

int main(void)
{
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		int N; cin >> N;
		cout << re(N) << '\n';
	
	
	}
	return 0;
}