///* Dynamic Programming */
//#include <iostream>
//
//using namespace std;
//
//int T;
//int n;
//
//int arr[11];
//
//int main(void)
//{
//	arr[1] = 1;
//	arr[2] = 2;
//	arr[3] = 4;
//	
//	for (int i = 4; i < 11; i++) {
//		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
//	}
//
//	cin >> T;
//	while (T--) {
//		cin >> n;
//		cout << arr[n] << '\n';
//	}
//	return 0;
//}


///* Àç±Í ÇÔ¼ö */
//#include <iostream>
//
//using namespace std;
//
//int func(int num,int n) { // n : target
//	int ans = 0;
//	if (num > n) return false;
//	if (num == n) return true;
//
//	for (int i = 1; i <= 3; i++) {
//		ans += func(num + i, n);
//	}
//	return ans;
//}
//
//int T;
//int n;
//
//int main(void) {
//	cin >> T;
//	while (T--) {
//		cin >> n;
//		cout << func(0, n) << '\n';
//	}
//	return 0;
//}