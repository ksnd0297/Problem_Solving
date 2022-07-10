#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
vector<char> alpha;

void password(string pass, int idx) {
	if (pass.size() == L) {
		int mo = 0, ja = 0;
		for (int i = 0; i < pass.size(); i++) {
			if (pass[i] == 'a' || pass[i] == 'e' || pass[i] == 'i' || pass[i] == 'o' || pass[i] == 'u') mo++;
			else ja++;
		}

		if (mo >= 1 && ja >= 2) {
			for (int i = 0; i < pass.size(); i++) cout << pass[i];
			cout << '\n';
		}
		return;
	}
	for (int i = idx; i < C; i++) {
		pass.push_back(alpha[i]);
		password(pass, i + 1);
		pass.pop_back();
	}
}

int main(void)
{
	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		char ch; cin >> ch;
		alpha.push_back(ch);
	}

	sort(alpha.begin(), alpha.end());

	password("", 0);

	return 0;
}
