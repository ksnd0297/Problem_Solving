#include <iostream>

using namespace std;

int N;

int main(void)
{
	cin >> N;

	int line = 2;
	for (int i = 0; i < N; i++) {
		line = line * 2 - 1;
	}
	cout << line * line;

	return 0;
}