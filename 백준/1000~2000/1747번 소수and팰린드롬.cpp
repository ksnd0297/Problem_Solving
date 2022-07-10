#include <iostream>
#include <string>
#include <math.h>

using namespace std;

bool arr[1000001]; // Å©±â : 100000001

int temp[1000001];

bool judge(int i) {
	string temp = to_string(i);
	int size = temp.size() / 2;
	for (int i = 0; i < size; i++) if (temp[i] != temp[temp.size() - 1 - i]) return false;
	return true;
}



int main(void)
{
	int a; cin >> a;
	for (int i = 2; i <= 1000000; i++) {
		if (i >= 1000000) break;
		if (arr[i] == true) continue;
		if (i >= 1 && judge(i)) temp[i] = true;
		for (int j = i + i; j < 1000000; j += i) arr[j] = true;
	}

	for (int i = a; i <= 1000000; i++) {
		if (temp[i]) {
			cout << i;
			return 0;
		}
	}

	return 0;
}