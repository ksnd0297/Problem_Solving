#include <iostream>
#include <string>
#include <math.h>

using namespace std;

bool arr[10000001]; // Å©±â : 100000001

bool judge(int i) {
	string temp = to_string(i);
	int size = temp.size() / 2;
	for (int i = 0; i < size; i++) if (temp[i] != temp[temp.size() - 1 - i]) return false;
	return true;
}



int main(void)
{
	int a, b;
	cin >> a >> b;
	for (int i = 2; i <= b; i++) {
		if (i >= 10000000) break;
		if (arr[i] == true) continue;
		if (i >= a && judge(i)) cout << i << '\n';
		for (int j = i + i; j < 10000000; j += i) arr[j] = true;
	}

	cout << -1;

	return 0;
}