#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;
	for(int i=1;i<=T;i++) {
		int N; string qus;
		cin >> N >> qus;
		qus.erase(N - 1, 1);
		cout << i << ' ' << qus << '\n';
	}
	return 0;
}