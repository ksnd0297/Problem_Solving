#include <iostream>

using namespace std;

int func(int num) {
	int po = 0;
	int count = 0;
	int six = 0;
	while (num != 0) {
		if (num % 10 == 6) {
			count++; six++;
		}
		else if (num % 10 != 6 && six < 3) six = 0;
		num /= 10;
	}
	if (six >= 3) return count;
	else return 0;
}

int main() {
	int N;
	cin >> N;

	int num = 666;
	int count = 0;
	while (1) {
		if (func(num) >= 3) count++;
		if (count == N) break;
		num++;
	}
	cout << num;
}