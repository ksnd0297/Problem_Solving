#include <iostream>

using namespace std;

int main(void)
{
	int L, P;
	cin >> L >> P;
	int ans = L * P;

	for (int i = 0; i < 5; i++) {
		int num;
		cin >> num;
		cout << num - ans << ' ';
	}
	return 0;
}