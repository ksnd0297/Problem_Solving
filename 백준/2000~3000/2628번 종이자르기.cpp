#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Garo, Sero;
int N;
int a, b;

int arr[101][101];
int check[101][101];
int ans[10001];

int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

void DFS(int y, int x, int p,int Temp) {
	check[y][x] = Temp;

	for (int k = 0; k < 4; k++) {
		int tempY = y + dir[k][0];
		int tempX = x + dir[k][1];
		if (y >= 0 && y < Sero && x >= 0 && x < Garo) {
			if (!check[tempY][tempX] && arr[tempY][tempX] == p)
				DFS(tempY, tempX, p, Temp);
		}
	}
}

int main(void)
{
	cin >> Garo >> Sero;
	cin >> N;

	for (int k = 1; k <= N; k++) {
		cin >> a >> b;
		if (a == 0) { // 0 : 가로로 자름 (위의 값 변경)
			for (int i = 0; i < b; i++) {
				for (int j = 0; j < Garo; j++) {
					arr[i][j]++;
				}
			}
		}
		else if (a == 1) { // 1 : 세로로 자름 (왼쪽 값 변경) 
			for (int i = 0; i < Sero; i++) {
				for (int j = 0; j < b; j++) {
					arr[i][j]++;
				}
			}
		}
	}

	int Temp = 1; 
	for (int i = 0; i < Sero; i++) {
		for (int j = 0; j < Garo; j++) {
			if (!check[i][j]) {
				DFS(i, j, arr[i][j], Temp);
				Temp++;
			}
		}
	}

	for (int i = 0; i < Sero; i++) {
		for (int j = 0; j < Garo; j++) {
			ans[check[i][j]]++;
		}
	}
	
	sort(ans, ans + Temp);
	cout << ans[Temp - 1];
	return 0;
}