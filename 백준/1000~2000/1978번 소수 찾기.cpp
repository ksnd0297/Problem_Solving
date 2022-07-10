#include <iostream>
using namespace std;

bool arr[10000];
int cnt;

int main(void) {
	for (int i = 2; i <= 10000; i++) {
		if (arr[i]) continue;
		for (int j = i + i; j <= 10000; j += i) {
			arr[j] = true; cnt++;
		}
	}
	cout << cnt;
	return 0;
}