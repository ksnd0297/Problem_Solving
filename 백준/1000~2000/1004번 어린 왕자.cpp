#include <bits/stdc++.h>

using namespace std;

int T;
int N;
int xA, yA, xB, yB;


int Pow(int N) {
	return N * N;
}

bool IsInside(int xD, int yD, int xC, int yC, int rC) { 
	if (Pow(xD - xC) + Pow(yD - yC) < Pow(rC)) return true;
	return false;
}

int main(void) {
	cin >> T;

	while (T--) {
		cin >> xA >> yA >> xB >> yB;
		int ans = 0;

		cin >> N;
		for (int i = 0; i < N; i++) {
			int xC, yC, rC; cin >> xC >> yC >> rC;
			bool flagA = IsInside(xA, yA, xC, yC, rC);
			bool flagB = IsInside(xB, yB, xC, yC, rC);
			if (flagA ^ flagB) ans++;
		}
		cout << ans << '\n';
	}
}