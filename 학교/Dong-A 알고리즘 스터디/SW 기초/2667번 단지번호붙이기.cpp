#include <bits/stdc++.h>
using namespace std;

int N;
int arr[26][26];
int check[26][26];

int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

int cnt = 0;

void DFS(int y, int x) {
	check[y][x] = true; cnt++;

	for (int i = 0; i < 4; i++) {
		int tempY = y + dir[i][0];
		int tempX = x + dir[i][1];
		if (tempY >= 0 && tempY < N && tempX >= 0 && tempX < N) {
			if (!check[tempY][tempX] && arr[tempY][tempX] == 1) {
				check[tempY][tempX] = true; 
				DFS(tempY, tempX);
			}
		}
	}
}

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char Num; cin >> Num;
			arr[i][j] = Num - '0';
		}
	}

	vector<int> ans;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1 && check[i][j] == 0 ) {
				DFS(i, j);
				ans.push_back(cnt); cnt = 0;
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';

	return 0;
}