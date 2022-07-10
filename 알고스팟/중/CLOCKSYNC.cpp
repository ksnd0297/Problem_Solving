#include <iostream>

using namespace std;

int myClock[16]; // 0 : 12시 1 : 3시 2 : 6시 3 : 9시

bool sync[10][16] = {
	{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0}, // 0
	{0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0}, // 1
	{0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1}, // 2
	{1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0}, // 3
	{0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0}, // 4
	{1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1}, // 5
	{0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1}, // 6
	{0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1}, // 7
	{0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0}, // 8
	{0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0}, // 9
};

bool checkClock() {
	for (int i = 0; i < 16; i++) {
		if (myClock[i] != 0) return false;
	}
	return true;
}

void setSwitch(int sw) {
	for (int i = 0; i < 16; i++) {
		if (sync[sw][i]) {
			myClock[i] += sync[sw][i];
			myClock[i] %= 4;
		}
	}
}

int clockSync(int sync, int cnt) {
	int ret = 123456789;
	if (checkClock()) return cnt;

	for (int sw = sync; sw < 10; sw++) {
		for (int k = 0; k < 4; k++) { // 4번 누르면 원래 상태로 복구
			setSwitch(sw);
			ret = min(ret, k + clockSync(sw + 1, cnt + 1));
		}
	}
	return ret;
}

int main(void)
{
	int C; cin >> C;
	while (C--) {
		for (int i = 0; i < 16; i++) {
			cin >> myClock[i];
			myClock[i] = (myClock[i] / 3) % 4;
		}
		int ans = clockSync(0, 0);
		if (ans == 123456789) cout << -1 << '\n';
		else cout << ans << '\n';
	}

	return 0;
}