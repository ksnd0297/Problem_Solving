#include <iostream>

using namespace std;

int ma[2001]; //메인 출력에 이용할 값
int temp[2001]; // 각 rept마다 더할 값 저장

void bigSum(int rept) {
	int carry = 0; //캐리 체크
	int sum = 0;
	for (int i = 0; i < rept-1; i++) { // 그 사이 루틴만큼 반복.
		for (int i = 2000; i >= 0; i--) {
			ma[i] = ma[i] + temp[i] + carry;
			carry = ma[i] / 10;
			ma[i] = ma[i] % 10;
		}
	}
	for (int i = 0; i <= 2000; i++) temp[i] = ma[i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;

	ma[2000] = 1; temp[2000] = 1; // 메인의 첫 번째 루틴 값 저장
	for (int rept = 2; rept <= N; rept++) { // 두 번째 루틴부터 시작
		bigSum(rept);
	}

	int count = 0;
	for (int i = 2000; i >= 0; i--) {
		if (ma[i] == 0)count++;
		else break;
	}
	cout << count;
}