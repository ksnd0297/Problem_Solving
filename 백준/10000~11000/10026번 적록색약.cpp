#include <iostream>

using namespace std;

int xtar[] = { -1,1,0,0 };
int ytar[] = { 0,0,-1,1 };

int check[101][101]; 
char color[101][101]; // 일반인
char colorw[101][101]; // 적록색약 : 적색과 녹색이 같게보임

int N;

void dfs(int y, int x) {
	int tary, tarx;
	for (int i = 0; i < 4; i++) {
		tary = y + ytar[i]; tarx = x + xtar[i];
		if (tary >= 0 && tary < N && tarx >= 0 && tary < N) {
			if (check[tary][tarx]) continue;
			else if (!check[tary][tarx] && color[y][x] == color[tary][tarx]) {
				check[tary][tarx] = check[y][x];
				dfs(tary, tarx);
			}
		}
	}
}

void dfsw(int y, int x) {
	int tary, tarx;
	for (int i = 0; i < 4; i++) {
		tary = y + ytar[i]; tarx = x + xtar[i];
		if (tary >= 0 && tary < N && tarx >= 0 && tary < N) {
			if (check[tary][tarx]) continue;
			else if (!check[tary][tarx] && colorw[y][x] == colorw[tary][tarx]) {
				check[tary][tarx] = check[y][x];
				dfsw(tary, tarx);
			}
		}
	}
}

int main() {
	cin >> N;
	char c;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> c;
			color[i][j] = c;
			if (c == 'G') colorw[i][j] = 'R'; // 녹색은 빨강 취급
			else colorw[i][j] = c;
		}
	}
	
	//color 배열 먼저 DFS
	int cnt = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!check[i][j]) {
				check[i][j] = cnt++;
				dfs(i, j); // (y , x)
			}
		}
	} 
	cout << cnt-1 << ' ';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			check[i][j] = false;
		}
	}
	cnt = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!check[i][j]) {
				check[i][j] = cnt++;
				dfsw(i, j); // (y , x)
			}
		}
	}
	cout << cnt-1;
	return 0;
}