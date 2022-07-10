#include <iostream>
#include <vector>

using namespace std;

int T;
int k;

vector<int> lotto;

void func(vector<int> ve, int index) {
	if (ve.size() == 6) {
		for (int i = 0; i < ve.size(); i++) cout << ve[i] << ' ';
		cout << '\n';
	}

	for (int i = index; i < lotto.size(); i++) {
		ve.push_back(lotto[i]); // 그 자리를 택하고
		func(ve, i + 1); // 택한것을 기준으로 들어가고
		ve.pop_back(); // 그 경우를 다 봤으면 제거
	}
}

int main(void) {
	while (1) {
		cin >> k;
		if (k == 0) break;

		for (int i = 0; i < k; i++) {
			int num; cin >> num;
			lotto.push_back(num);
		}

		vector<int> ve;
		func(ve, 0);

		lotto.clear();
		cout << '\n';
	}

	return 0;
}