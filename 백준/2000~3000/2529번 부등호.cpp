#include <iostream>
#include <string>
#include <vector>

using namespace std;

int k;
string ans;

string minAns = "9876543210";
string maxAns = "0";

bool check[10];

void func(int index, string& ve) {
	bool flag = false;
	if (ve.size() != 0) {
		for (int i = 0; i < ve.size() - 1; i++) {
			if (ans[i] == '>') {
				if (ve[i] - '0' < ve[i + 1] - '0') flag = true;
			}
			else if (ans[i] == '<') {
				if (ve[i] - '0' > ve[i + 1] - '0') flag = true;
			}
		}
		if (flag) return;
	}

	if (ve.size() == k + 1) {
		if (stoll(minAns) > stoll(ve)) minAns = ve;
		if (stoll(maxAns) < stoll(ve)) maxAns = ve;
		return;
	}


	for (int i = 0; i <= 9; i++) {
		if (!check[i]) {
			ve.push_back(i + '0');
			check[i] = true;
			func(index + 1, ve);
			ve.pop_back();
			check[i] = false;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> k;
	for (int i = 0; i < k; i++) {
		char ch; cin >> ch;
		ans += ch;
	}

	string ve;
	func(0, ve);

	cout << maxAns << '\n';
	cout << minAns << '\n';

	return 0;
}