#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string arr[10001];

string add(string A, string B) { // A : 12345 B :345
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

int main(void) {
	int N;
	cin >> N;
	arr[0] = "0";
	arr[1] = "1";
	arr[2] = "1";
	for (int i = 3; i <= N; i++) {
		arr[i] = add(arr[i - 1],arr[i - 2]);
	}
	cout << arr[N];

	return 0;
}