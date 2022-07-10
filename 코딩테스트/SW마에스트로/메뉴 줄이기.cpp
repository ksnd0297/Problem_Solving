#include <iostream>
#include <vector>

using namespace std;

int N, M, K;

int menu[1001][16]; // [a][b] a 손님의 b 메뉴 선호도

bool check[16];

int judge() {
	int temp = 0;
	for (int i = 0; i < N; i++) {
		bool flag = false;
		for (int j = 0; j < M; j++) {
			if (menu[i][j] >= 5) flag = true;
		}
		if (!flag) temp++;
	}
	return N - temp;
}

int func(vector<int>ve, int index) {
	int ans = 0;
	if (ve.size() == K) { // 삭제할 메뉴 도달
		for (int i = 0; i < ve.size(); i++) {
			for (int j = 0; j < N; j++) {
				menu[j][ve[i]] *= -1; // 음수면 사지 않는다
			}
		}
		int ret = judge();
		for (int i = 0; i < ve.size(); i++) {
			for (int j = 0; j < N; j++) {
				menu[j][ve[i]] *= -1; // 음수면 사지 않는다
			}
		}
		return ret;
	}

	for (int i = index; i < M; i++) {
		ve.push_back(i);
		ans = max(ans, func(ve, i + 1));
		ve.pop_back();
	}
	return ans;
}

int main(void) {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int num; cin >> num;
			menu[i][j] = num;
		}
	}

	vector<int>ve;
	cout << func(ve, 0);

	return 0;
}