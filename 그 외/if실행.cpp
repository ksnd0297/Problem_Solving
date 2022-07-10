#include <iostream>

using namespace std;

int main(void) {
	bool e1 = false;
	bool e2 = true;
	int s1 = 10; int s2 = 20;

	if (e1) if (e2) cout << s1; else cout << s2;

	return 0;
}