#include <bits/stdc++.h>

using namespace std;

int w, h;
int p, q;
int t;

int main(void) {
	cin >> w >> h;
	cin >> p >> q;
	cin >> t;

	int x = 0, y = 0;
	if (((p + t) / w) % 2 == 0) {
		x = (p + t) % w;
	}
	else {
		x = w - (p + t) % w;
	}
	if (((q + t) / h) % 2 == 0) {
		y = (q + t) % h;
	}
	else {
		y = h - (q + t) % h;
	}
	
	cout << x << ' ' << y;
	
	return 0;
}