#include <cstdio>
#include <iostream>
#include <string>
#pragma warning(disable: 4996)

using namespace std;

int N;
string str;

string Type1(int num) { // R1C1 *
	string retC = "";
	while (num > 26) {
		if (num % 26 == 0) {
			retC += 'Z'; num--;
		}
		else retC += num % 26 + 'A' - 1;
		num /= 26;
	}
	retC += num + 'A' - 1;
s
	reverse(retC.begin(), retC.end());
	return retC;
}

string Type2(string& str) { // BC23
	string R = "";
	int index;
	for (index = str.size() - 1; index >= 0; index--) {
		if (str[index] >= '0' && str[index] <= '9') R += str[index];
		else break;
	}
	reverse(R.begin(), R.end());
	int num = 0; int C = 0;
	do {
		int mul = pow(26, num);
		C += mul * (str[index] - 'A' + 1);
		num++; index--;
	} while (index != -1);
	return 'R' + R + 'C' + to_string(C);
}


int main(void)
{
	freopen("spreadsheet.inp", "r", stdin);
	freopen("spreadsheet.out", "w", stdout);

	cin >> N;
	while (N--) {
		char c1 = 0, c2 = 0;
		int n1 = 0, n2 = 0;
		cin >> str;
		sscanf(str.c_str(), "%c%d%c%d", &c1, &n1, &c2, &n2);
		if (c1 == 'R' && c2 == 'C') {
			cout << Type1(n2) << n1 << '\n';
		}
		else cout << Type2(str) << '\n';
	}
	return 0;
}