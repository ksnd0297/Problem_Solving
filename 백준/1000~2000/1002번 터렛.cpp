#include <bits/stdc++.h>

using namespace std;

int T;
int xA, yA, rA, xB, yB, rB;

int Pow(int x) {
	return (int)pow(x, 2);
}

bool IsInside() { // 원 안에 다른 원의 중심점이 존재한다.
	if (Pow(xB - xA) + Pow(yB - yA) < Pow(max(rA, rB))) return true;
	return false;
}

int main(void) {
	cin >> T;
	while (T--) {
		cin >> xA >> yA >> rA >> xB >> yB >> rB;

		int ans = 0;

		if (xA == xB && yA == yB && rA == rB) ans = -1;
		else if (IsInside()) {
			if ((int)sqrt(Pow(xB - xA) + Pow(yB - yA)) + min(rA, rB) < max(rA, rB)) ans = 0;
			else if ((int)sqrt(Pow(xB - xA) + Pow(yB - yA)) + min(rA, rB) == max(rA, rB)) ans = 1;
			else ans = 2;
		}
		else {
			if (Pow(xB - xA) + Pow(yB - yA) == Pow(rA + rB)) ans = 1;
			else if (Pow(xB - xA) + Pow(yB - yA) < Pow(rA + rB)) ans = 2;
			else if (Pow(xB - xA) + Pow(yB - yA) > Pow(rA + rB)) ans = 0;
		}

		cout << ans << '\n';
	}
	return 0;
}