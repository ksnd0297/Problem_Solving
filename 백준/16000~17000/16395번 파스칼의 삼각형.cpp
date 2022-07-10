#include <iostream>
#include <string.h>

using namespace std;

long long int ans[31][31];

long long int com(int a, int b) {
	long long int& ret = ans[a][b];
	if (ret != -1) return ret;
	if (b == 1) return 1;
	if (b == a) return 1;
	return ret = com(a - 1, b) + com(a - 1, b - 1);
}

int main(void) {
	int a, b; cin >> a >> b;
	memset(ans, -1, sizeof(ans));
	cout << com(a , b );
	return 0;
}