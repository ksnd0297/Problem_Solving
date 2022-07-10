#include <bits/stdc++.h>
using namespace std;

int dir[8][2] = { {-2 ,1},{ -1, 2},{1, 2},{2, 1},{2, -1},{1, -2},{-1, -2},{-2, -1} };
int arr[6][6];

string qus;

//bool dfs1(int y, int x, int num) { //  0 - > 35
//	if (num == 35) return true;
//
//	for (int i = 0; i < 8; i++) {
//		int tempY = y + dir[i][0];
//		int tempX = x + dir[i][1];
//		if (tempY >= 0 && tempY < 6 && tempX >= 0 && tempX < 6) {
//			if (arr[tempY][tempX] == num + 1) {
//				return dfs1(tempY, tempX, num + 1);
//			}
//		}
//	}
//	return false;
//}

bool dfs2(int y, int x, int num) { // 35 - > 0 
	if (num == 0) return true;

	for (int i = 0; i < 8; i++) {
		int tempY = y + dir[i][0];
		int tempX = x + dir[i][1];
		if (tempY >= 0 && tempY < 6 && tempX >= 0 && tempX < 6) {
			if (arr[tempY][tempX] == num - 1) {
				return dfs2(tempY, tempX, num - 1);
			}
		}
	}
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 36; i++) {
		cin >> qus;
		arr[qus[0] - 'A'][qus[1] - '0' - 1] = i;
	}

	bool flag1 = false;
	bool flag2 = false;
	for (int i = 0; i < 6; i++) { // 0에서 시작
		for (int j = 0; j < 6; j++) {
			//if (arr[i][j] == 0) {
			//	flag1 = dfs1(i, j, 0);
			//}
			if (arr[i][j] == 35) {
				flag2 = dfs2(i, j, 1);
			}
		}
	}
	if (flag2) cout << "Valid";
	else cout << "Invalid";

	return 0;
}