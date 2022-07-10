#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> C;

int func(int food, int kcal, int index) {
	int ans = 0;
	if (index > N) return 0;
	if (food == 3) {
		if (kcal >= 2000 && kcal <= 2500) return 1;
		return 0;
	}

	for (int i = index; i < N; i++) {
		ans += func(food + 1, kcal + C[i], i + 1);
	}
	return ans;
}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		C.push_back(num);
	}

	cout << func(0, 0, 0); // ¸ÔÀº À½½Ä °³¼ö && Ä®·Î¸® && ÀÎµ¦½º

	return 0;
}