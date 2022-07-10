#include <iostream>
#include <string.h>

using namespace std;

int ans[100001];

int main(void) {
	int N; cin >> N;
	for (int i = 0; i <= N; i++) ans[i] = 123456789;
	ans[2] = 1; ans[4] = 2; ans[5] = 1;
	for (int i = 6; i <= N; i++) {
		if (ans[i - 2] != 123456789) ans[i] = ans[i - 2] + 1;
		if (ans[i - 5] != 123456789) ans[i] = min(ans[i],ans[i - 5] + 1);
	}
	if (ans[N] == 123456789) cout << -1;
	else cout << ans[N];
	return 0;
}