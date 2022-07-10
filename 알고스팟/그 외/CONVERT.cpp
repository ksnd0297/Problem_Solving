#include <iostream>

using namespace std;

int main() {
	int T; cin >> T;
	cout << fixed;
	cout.precision(4);
	for(int i=1;i<=T;i++) {
		double N; string qus; cin >> N >> qus;
		if (qus == "kg") cout << i << ' ' << N * 2.2046 << " lb" << '\n';
		else if (qus == "lb") cout << i << ' ' << N * 0.4536 << " kg" << '\n';
		else if (qus == "l") cout << i << ' ' << N * 0.2642 << " g" << '\n';
		else if (qus == "g") cout << i << ' ' << N * 3.7854 << " l" << '\n';
	}
	return 0;
}