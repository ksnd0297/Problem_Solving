#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable: 4996)

using namespace std;

int N;
vector<int> ve[10001];

bool check[10001][6];

int main(void) {
	//freopen("dice.inp", "r", stdin);
	//freopen("dice.out", "w", stdout);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 6; j++) {
			int num; cin >> num;
			ve[i].push_back(num);
		}
	}

	int ans = 0;
	int Up = 0;
	int Down = 0;
	for (int i = 0; i < 6; i++) { // 가장 아래주사위 결정
		if (i == 0) { Up = ve[0][0]; Down = ve[0][5]; }
		else if (i == 1) { Up = ve[0][1]; Down = ve[0][3]; }
		else if (i == 2) { Up = ve[0][2]; Down = ve[0][4]; }
		else if (i == 3) { Up = ve[0][3]; Down = ve[0][1]; }
		else if (i == 4) { Up = ve[0][4]; Down = ve[0][2]; }
		else if (i == 5) { Up = ve[0][5]; Down = ve[0][0]; }

		int sum = 0;
		for (int j = 0; j < 6; j++) {
			if (ve[0][j] != Up && ve[0][j] != Down) sum = max(sum, ve[0][j]);
		}

		for (int j = 1; j < N; j++) { // 윗면의 주사위와 아랫면 비교
			if (Up == ve[j][0]) { Up = ve[j][5]; Down = ve[j][0]; }
			else if (Up == ve[j][1]) { Up = ve[j][3]; Down = ve[j][1]; }
			else if (Up == ve[j][2]) { Up = ve[j][4]; Down = ve[j][2]; }
			else if (Up == ve[j][3]) { Up = ve[j][1]; Down = ve[j][3]; }
			else if (Up == ve[j][4]) { Up = ve[j][2]; Down = ve[j][4]; }
			else if (Up == ve[j][5]) { Up = ve[j][0]; Down = ve[j][5]; }

			int max = 0;
			for (int k = 0; k < 6; k++) {
				if (ve[j][k] != Up && ve[j][k] != Down) max = ::max(max, ve[j][k]);
			}
			sum += max;
		}
		ans = max(ans, sum);
	}
	cout << ans;

	return 0;
}