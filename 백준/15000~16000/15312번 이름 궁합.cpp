#include <bits/stdc++.h>

using namespace std;

int alpha[26] = { 3,2,1,2,3,3,2,3,3,2,2,1,2,2,1,2,2,2,1,2,1,1,1,2,2,1 };

char change(char ch) {
	return alpha[ch - 'A'] + '0';
}

void func(string& qus) {
	if (qus.size() == 2) {
		cout << qus;
		return;
	}
	string Temp = "";
	for (int i = 0; i < qus.size() - 1; i++) {
		int qus1 = qus[i] - '0';
		int qus2 = qus[i + 1] - '0';
		int sum = (qus1 + qus2) % 10;

		Temp += (sum + '0');
	}

	func(Temp);
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string A, B;
	cin >> A;
	cin >> B;

	string qus = "";
	for (int i = 0; i < A.size(); i++) {
		qus += change(A[i]);
		qus += change(B[i]);
	}

	func(qus);

	return 0;
}