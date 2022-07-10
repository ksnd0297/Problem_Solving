#include <iostream>
#include <string>
#include <vector>

using namespace std;

int C; int N;
string A, B;

vector<string> ans;

void compare(string& A, string& B) {
	int Aidx = 0;
	int Bidx = 0;
	bool flag = true; // A 와 B가 같은지 판단
	while (Aidx != A.size() && Bidx != B.size()) {
		if (A[Aidx] == '?') {
			Aidx++; Bidx++;
		}
		else if (A[Aidx] == '*') {
			Aidx++;
			while (A[Aidx] != B[Bidx] && Bidx < B.size()) Bidx++;
		}
		else {
			if (A[Aidx] == B[Bidx]) {z
				Aidx++; Bidx++;
			}
			else flag = false;
		}
	}
	if (flag) ans.push_back(B);
}

int main(void)
{
	cin >> C;
	while (C--) {
		cin >> A;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> B;
			compare(A, B);
		}
	}
	return 0;
}