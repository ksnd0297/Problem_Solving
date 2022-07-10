#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool check(string& exp) {
	stack<int> s;
	for (int i = 0; i < exp.size(); i++) {
		switch (exp[i]) {
			case'(': s.push(exp[i]); break;
			case'[': s.push(exp[i]); break;
			case'{':s.push(exp[i]); break;
			default: {
				if (s.size() != 0 && exp[i] - s.top() <= 2) s.pop();
				else return false;
			}
		}
	}
	if (s.size() != 0) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int C; cin >> C;
	while (C--) {
		string exp; cin >> exp;
		if (check(exp)) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}