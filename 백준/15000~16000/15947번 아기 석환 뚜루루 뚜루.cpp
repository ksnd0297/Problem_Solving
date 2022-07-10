#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string ans = "apple";

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}