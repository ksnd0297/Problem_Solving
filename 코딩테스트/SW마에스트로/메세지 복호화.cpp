#include <iostream>
#include <string>

using namespace std;

int a, b;
string qus;

int main(void) {
	cin >> a >> b;
	cin >> qus;

	for (int i = 0; i < qus.size(); i++) {
		for (int j = 1; j <= 26; j++) {
			if ((qus[i] - 'a') == (a * j + b) % 26) {
				if (j == 26) cout << 'a';
				else cout << (char)(j + 'a');
			}
		}
	}
	return 0;
}