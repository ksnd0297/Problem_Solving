#include <iostream>
#include <cstring>

using namespace std;

int alpha[26];
int temp[3]; // a + b = c (a, b, c ¿˙¿Â)

int alphatonum(string qus) {
	int sum = 0;
	for (int i = 0; i < (int)qus.size(); i++) {
		alpha[qus[i] - 'a']++;
		sum += qus[i] - 'a';
	}
	if (sum == 31) return 1;
	else if (sum == 55) return 2;
	else if (sum == 51) return 3;
	else if (sum == 56) return 4;
	else if (sum == 38 && alpha[5] == 1) return 5;
	else if (sum == 49) return 6;
	else if (sum == 60 && alpha[18] == 1) return 7;
	else if (sum == 45) return 8;
	else if (sum == 38) return 9;
	else if (sum == 60) return 0;
}


int main() {
	int C; cin >> C;
	while (C--) {
		string qus;
		bool flag1 = false, flag2 = false, flag3 = false;
		int index = 0;
		for (int i = 0; i < 5; i++) {
			cin >> qus;
			if (qus[0] == '+') flag1 = true;
			else if (qus[0] == '-') flag2 = true;
			else if (qus[0] == '*') flag3 = true;
			else if (qus[0] == '=') continue;
			else {
				temp[index++] = alphatonum(qus);
				memset(alpha, 0, sizeof(alpha));
			}
		}
		if (flag1) {
			if (temp[0] + temp[1] == temp[2]) cout << "Yes" << '\n';
			else cout << "No" << '\n';
		}
		else if (flag2) {
			if (temp[0] - temp[1] == temp[2]) cout << "Yes" << '\n';
			else cout << "No" << '\n';
		}
		else if (flag3) {
			if (temp[0] * temp[1] == temp[2]) cout << "Yes" << '\n';
			else cout << "No" << '\n';
		}
	}
	return 0;
}