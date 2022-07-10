#include <iostream>

using namespace std;

int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

int main(void)
{
	bool flag = false; // 5¸¦ ¸¸³µÀ» ¶§ break;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[j] == 5) {
				flag = true;
				break;
			}
		}
		if (flag == true) {
			break;
		}
	}
	
	flag = false;
	for (int i = 0; !flag && i < 10; i++) {
		for (int j = 0; !flag &&  j < 10; j++) {
			if (arr[j] == 5) flag = true;
		}
	}

	return 0;
}