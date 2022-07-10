#include <bits/stdc++.h>

using namespace std;

class Point {
public:
	int X;
	int Y;

	Point(int X = 0, int Y = 0) {
		this->X = X;
		this->Y = Y;
	}
};

Point P[4];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 1; i <= 3; i++) {
		int X, Y; cin >> X >> Y;
		P[i] = Point(X, Y);
	}
	if ((P[2].X - P[1].X) * (P[3].Y - P[2].Y) - (P[3].X - P[2].X) * (P[2].Y - P[1].Y) > 0) cout << 1;
	else if ((P[2].X - P[1].X) * (P[3].Y - P[2].Y) - (P[3].X - P[2].X) * (P[2].Y - P[1].Y) < 0) cout << -1;
	else cout << 0;

	return 0;
}