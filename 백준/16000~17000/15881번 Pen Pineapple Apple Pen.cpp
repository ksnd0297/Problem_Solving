#include <iostream>
#include <string>

using namespace std;

string ans;

int main(void) {
	int N; cin >> N;
	cin >> ans;

	int count = 0;
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] == 'p' && ans[i + 1] == 'P' && ans[i + 2] == 'A' && ans[i + 3] == 'p') {
			i += 3;
			count++;
		}
	}
	cout << count;
	return 0;
}