#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

string str;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (1) {
		cin >> str;
		if (str == "*") break;


		bool flag = false;
		for (int i = 1; !flag && i < str.size(); i++) {
			unordered_map<string, int> um;
			for (int j = 0;!flag &&  j < str.size() - i; j++) {
				string newStr = ""; newStr += str[j]; newStr += str[j + i];
				if (um.find(newStr) != um.end()) flag = true;
				else um.insert({ newStr, um.size() });
			}
		}
		if (!flag) cout << str << " is surprising." << '\n';
		else cout << str << " is NOT surprising." << '\n';
	}

	return 0;
}