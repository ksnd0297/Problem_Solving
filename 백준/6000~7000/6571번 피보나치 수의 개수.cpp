#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string str[501];

string add(string A, string B) {
	reverse(A.begin(), A.end()); reverse(B.begin(), B.end());
	int carry = 0;
	string C;
	for (int i = 0; i < A.size(); i++) {
		if (B.size() <= i) { C += (A[i] + carry); carry = 0; continue; }
		int num = (A[i] - '0') + (B[i] - '0') + carry;
		carry = num / 10;
		C += (num % 10) + '0';
	}
	if (carry) C += '1';
	reverse(C.begin(), C.end());
	return C;
}

int compare(string A,int num) {
	for (int i = 1; i < 500; i++) {
		if (str[i].size() > A.size()) return i - 1;
		else if (str[i].size() < A.size()) continue;
		else if (str[i].size() == A.size()) {
			int ans = A.compare(str[i]); // size가 같을 경우
			if (ans < 0) return i - 1;
			else if (ans == 0 && num) return i;
			else if (ans == 0 && !num) return i - 1;
		}
	}
}

int main(void)
{
	int temp;
	str[1] = "1"; str[2] = "2";
	for (int i = 3; i < 500; i++) {
		str[i] = add(str[i - 1],str[i - 2]);

	}
	string A, B;
	while (1) {
		cin >> A >> B;
		if (A == "0" && B == "0") break;
		cout << compare(B,1) - compare(A,0) << '\n';
	}
	return 0;
}