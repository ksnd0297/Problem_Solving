#include <iostream>
#include <string>

using namespace std;

string com[101][101];

string Sum(string A, string B) {
	if (A.size() < B.size()) return Sum(B, A);
	string C;
	for (int i = B.size() - 1; i >= 0; i--) {
		bool carry = false;
		char ch;
		if (carry) {
			ch = A[i] + B[i] - 96;
			C += ch;
		}
		else {
			ch = A[i] + B[i] - 48;
			if (ch - '0' >= 10) {
				carry = true;
				C += ch - 10;
			}
			else C += ch;
		}
	}
	string temp;
	for (int i = C.size() - 1; i >= 0; i--) temp += C[i];
	return temp;
}

string combination(int n, int r) {
	string& ret = com[n][r];
	if (r == 0) return ret = "1";
	if (n == r) return ret = "1";
	if (ret != "-1") return ret;
	return ret = Sum(combination(n - 1, r - 1), combination(n - 1, r));
}

int main() {
	int N, R; cin >> N >> R;
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			com[i][j] = "-1";

	cout << combination(N, R);

	return 0;
}