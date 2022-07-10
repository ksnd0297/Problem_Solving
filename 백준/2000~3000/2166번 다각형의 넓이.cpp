#include <bits/stdc++.h>
#define MABS(x) ((x)<0?-(x):(x))

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

vector<Point>ve;

int N;
long long ans;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int X, Y; cin >> X >> Y;
		ve.push_back(Point(X, Y));
	}


	for (int i = 0; i < ve.size() - 1; i++) {
		ans +=  1LL * ve[i].X * ve[i + 1].Y - 1LL * ve[i].Y * ve[i + 1].X;
	}

	ans += (1LL * ve[ve.size() - 1].X * ve[0].Y) - (1LL * ve[0].X * ve[ve.size() - 1].Y);

	printf("%.1f", MABS(ans) / 2.0);

	return 0;
}