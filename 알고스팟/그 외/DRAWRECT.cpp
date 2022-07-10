#include <iostream>

using namespace std;

pair<int, int> dot[3];

int main() {
	int T; cin >> T;
	while (T--) {
		for (int i = 0; i < 3; i++) {
			int x, y; cin >> x >> y;
			dot[i] = make_pair(x, y);
		}
		int ansx, ansy;
		for (int i = 0; i < 3; i++) {
			ansx = dot[i].first; int count = 0;
			for (int j = 0; j < 3; j++) {
				if (j != i) {
					if (ansx == dot[j].first) break;
					else count++;
				}
			}
			if (count == 2) break;
		}
		for (int i = 0; i < 3; i++) {
			ansy = dot[i].second; int count = 0;
			for (int j = 0; j < 3; j++) {
				if (j != i) {
					if (ansy == dot[j].second) break;
					else count++;
				}
			}
			if (count == 2) break;
		}
		cout << ansx << ' ' << ansy << '\n';
	}

	return 0;
}