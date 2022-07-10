#include <iostream>
#include <string>

using namespace std;

int N, k;

int main(void)
{
	cin >> N >> k;
	
	if (k < 10) { // 수가 10 보다 작을 경우
		if (N < k) cout << -1;
		else cout << k;
		return 0;
	}

	int Num = 10; // 실제 수
	int Digits = 10; // 자리 수
	string tempNum;
	while (Digits <= k) {
		tempNum = to_string(Num);
		Num += 1;
		Digits += tempNum.length();
	}
	Num -= 1; Digits -= tempNum.length();
	if (Num > N) cout << -1;
	else {
		k -= Digits;
		if (k > (tempNum.length()-1)) cout << -1;
		else cout << tempNum[k];
	}

	return 0;
}