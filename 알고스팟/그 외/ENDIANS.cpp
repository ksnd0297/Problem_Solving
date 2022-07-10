#include <iostream>
#include <cstring>
using namespace std;

int endian[32];
int cendian[32];

void InsertEndian(long long int num) {
	int pos = 31;
	while (num != 0) {
		endian[pos--] = num % 2;
		num /= 2;
	}
}

void changeEndian() {
	int pos = 0;
	for (int i = 24; i >= 0; i -= 8) {
		for (int j = 0; j < 8; j++) {
			cendian[pos++] = endian[i + j];
		}
	}
}

int main() {
	int C; cin >> C;
	while (C--) {
		long long int num; cin >> num;
		InsertEndian(num);
		changeEndian();
		long long int ans = 0; long long int k = 1;
		for (int i = 31; i >= 0; i--) {
			ans += cendian[i] * k;
			k *= 2;
		}
		cout << ans << '\n';
		memset(endian, false, sizeof(endian));
		memset(cendian, false, sizeof(endian));
	}
	return 0;
}