#include <iostream>

using namespace std;

double dp[51][51][51];
int dir[8][2] = { {1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2} };
int N, K;
double rec(int x, int y, int depth, double perc) {
	double& ret = dp[x][y][depth];
	if (ret != 0) return ret;
	if (depth == K) return perc;
	for (int i = 0; i < 8; i++) {
		int tempx = x + dir[i][0];
		int tempy = y + dir[i][1];
		if (tempx >= 0 && tempx < N && tempy >= 0 && tempy < N) {
			ret += rec(tempx, tempy, depth + 1, perc / 8);
		}
	}
	return ret;
}

int main(void)
{
	int x, y;
	cout << fixed;
	cout.precision(10);
	cin >> N >> x >> y >> K;
	cout << rec(x-1, y-1, 0, 1);
	return 0;
}