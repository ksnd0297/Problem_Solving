#include <iostream>
#include <math.h>

using namespace std;

int T;
int x, y;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--) {
		bool flag = false; // Â÷°¡ È¦¼ö
		cin >> x >> y;
		long long int ans = 0;
		long long int i = 1;
		long long int pos = x;
		for (; i <= y; i++) {
			if (x + (i * i) > y) {
				ans += (i-1) + (i - 2); 
				pos = x + ((i - 1) * (i - 1));
				break; // 0 - 16 ans = 7 < 1 2 3 4 3 2 1 > i -1 =  4
			}
		}
		long long int max = (i - 1);
		while (1) {
			if (pos + max <= y) {
				pos += max;
				ans++;
			}
			else max--;
			if (pos == y) break;
		}
		cout << (long long int)ans << '\n';
	}
	return 0;
}