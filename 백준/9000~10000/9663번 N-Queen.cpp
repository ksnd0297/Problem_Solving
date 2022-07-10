#include <iostream>

using namespace std;

int queen[15]; // [4] = 2  : 4 행 2열에 queen 존재
int N;
int cnt;

void dfs(int row) { // 행
	if (row == N) { cnt++; return; }
	for (int i = 0; i < N; i++) { // 몇 번째 열에 들갈 수 있는가
		bool flag = true;
		for (int j = 0; flag && j < row; j++) {
			if (queen[j] == i || abs(row - j) == abs(i - queen[j])) {
				flag = false;
			}
		}
		if (flag) {
			queen[row] = i;
			dfs(row + 1);
		}
	}
}

int main(void)
{
	cin >> N;
	dfs(0);
	cout << cnt;
	return 0;
}