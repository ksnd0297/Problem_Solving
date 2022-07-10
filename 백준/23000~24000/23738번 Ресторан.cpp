#include <iostream>
#include <string>

using namespace std;

string qus, ans;

int main(void)
{
	cin >> qus;
	for (int i = 0; i < qus.size(); i++) {
		if (qus[i] == 'B') ans.append("v");
		else if (qus[i] == 'E') ans.append("ye");
		else if (qus[i] == 'H') ans.append("n");
		else if (qus[i] == 'P') ans.append("r");
		else if (qus[i] == 'C') ans.append("s");
		else if (qus[i] == 'Y') ans.append("u");
		else if (qus[i] == 'X') ans.append("h");
		else ans.push_back(qus[i] + 32);
	}
	cout << ans;
	return 0;
}