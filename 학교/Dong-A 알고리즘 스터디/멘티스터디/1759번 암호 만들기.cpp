#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;

vector<char> alpha;

void func(vector<char> ve, int index) {
	if (ve.size() == L) {
		int mo = 0, za = 0; // 모음 자음
		for (int i = 0; i < ve.size(); i++) {
			if (ve[i] == 'a' || ve[i] == 'e' || ve[i] == 'i' || ve[i] == 'o' || ve[i] == 'u') mo++;
			else za++;
		}

		if (mo >= 1 && za >= 2) {
			for (int i = 0; i < ve.size(); i++) {
				cout << ve[i];
			}
			cout << '\n';
		}
		return;
	}

	// 지금의 자리에서 이 글자를 넣을까 말까
	for (int i = index; i < alpha.size(); i++) {
		ve.push_back(alpha[i]);
		func(ve, i + 1);
		ve.pop_back();
	}
}

// alpha : a t c i s w

int main(void) {
	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		char ch; cin >> ch;
		alpha.push_back(ch);
	}
	sort(alpha.begin(), alpha.end());

	vector<char> ve;
	func(ve, 0);

	return 0;
}