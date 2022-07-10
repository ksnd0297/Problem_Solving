#include <iostream>
#include <string.h>

using namespace std;

long long int ans[31][31];

long long int com(int a, int b) {
	if (b == 1) return a;
	if (b == a) return 1;
	long long int& ret = ans[a][b];
	if (ret != -1) return ret;

	return ret = com(a - 1, b) + com(a - 1, b - 1);
}

int main(void) {
	int N; cin >> N;
	while (N--) {
		int a, b; cin >> a >> b;
		memset(ans, -1, sizeof(ans));
		cout << com(b, a) << '\n';
	}
	return 0;
}