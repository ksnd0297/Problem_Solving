#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string arr[20] = { "1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20" };

int main(void) {
	for (int i = 0; i < 10; i++) {
		int A, B; cin >> A >> B;
		reverse(arr + A-1, arr + B);
	}
	for (int i = 0; i < 20; i++) cout << arr[i] << ' ';
	return 0;
}