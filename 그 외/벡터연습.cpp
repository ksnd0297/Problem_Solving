#include <iostream>
#include  <string>

using namespace std;

int N;
string qus;

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		getline(cin, qus);
		cout << qus << '\n';
	}

	return 0;
}