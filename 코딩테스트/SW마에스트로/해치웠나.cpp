#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack <int> s;

bool func(string& b) {
	for (int i = 0; i < b.size(); i++) {
		if (b[i] == '(') s.push(b[i]);
		else if (b[i] == ')') {
			if (s.empty()) return false;
			
			if (s.top() == '(') s.pop();
			else return false;
		}
	}
	if (!s.empty()) return false;
	return true;
}

int main(void)
{
	string b;
	cin >> b;
	if (func(b)) cout << "YES";
	else cout << "NO";
	
	return 0;
}