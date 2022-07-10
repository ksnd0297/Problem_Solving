#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string ans; cin >> ans;
	int sum = 0;
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] >= 'A' && ans[i] <= 'C') sum += 3;
		else if (ans[i] >= 'D' && ans[i] <= 'F') sum += 4;
		else if (ans[i] >= 'G' && ans[i] <= 'I') sum += 5;
		else if (ans[i] >= 'J' && ans[i] <= 'L') sum += 6;
		else if (ans[i] >= 'M' && ans[i] <= 'O') sum += 7;
		else if (ans[i] >= 'P' && ans[i] <= 'S') sum += 8;
		else if (ans[i] >= 'T' && ans[i] <= 'V') sum += 9;
		else if (ans[i] >= 'W' && ans[i] <= 'Z') sum += 10;
	}
	cout << sum;
	return 0;
}