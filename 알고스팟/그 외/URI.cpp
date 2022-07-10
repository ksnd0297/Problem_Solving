#include <iostream>
#include <string>

using namespace std;

string qus;

void change(int pos) {
	if (qus[pos] == '0') {
		qus[pos - 2] = ' ';
		qus.erase(pos - 1, 2);
	}
	else if (qus[pos] == '1') {
		qus[pos - 2] = '!';
		qus.erase(pos - 1, 2);
	}
	else if (qus[pos] == '4') {
		qus[pos - 2] = '$';
		qus.erase(pos - 1, 2);
	}
	else if (qus[pos] == '5') {
		qus[pos - 2] = '%%';
		qus.erase(pos - 1, 2);
	}
	else if (qus[pos] == '8') {
		qus[pos - 2] = '(';
		qus.erase(pos - 1, 2);
	}
	else if (qus[pos] == '9') {
		qus[pos - 2] = ')';
		qus.erase(pos - 1, 2);
	}
	else if (qus[pos] == 'a') {
		qus[pos - 2] = '*';
		qus.erase(pos - 1, 2);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int C; cin >> C;
	while (C--) {
		cin >> qus;
		
		int pos = 0;
		while (qus[pos] != '\0') {
			if (qus[pos] != '%') { pos++; }
			else if (qus[pos] == '%') {
				if (qus[pos + 1] == '2') {
					change(pos+2);
					pos += 1;
				}
			}
		}
		cout << qus << '\n';
	}
}