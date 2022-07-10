#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#pragma warning(disable :4996)

using namespace std;

int T, N;
int block[1001][1001];

void blockCheck(int y, int x) {
	int blankCnt = 0;
	if (block[y][x] == -1) blankCnt++;
	if (block[y + 1][x] == -1) blankCnt++;
	if (block[y + 1][x + 1] == -1) blankCnt++;
	if (blankCnt == 1) {
		if (block[y][x] == -1) block[y][x] = (block[y + 1][x] + block[y + 1][x + 1]) % 100;
		else if (block[y + 1][x] == -1) block[y + 1][x] = (block[y][x] - block[y + 1][x + 1] + 100) % 100;
		else if (block[y + 1][x + 1] == -1) block[y + 1][x + 1] = (block[y][x] - block[y + 1][x] + 100) % 100;
	}
}

int main(void) {
	freopen("block.inp", "r", stdin);
	freopen("block.out", "w", stdout);

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < y + 1; x++)
			{
				cin >> block[y][x];
			}
		}
		for (int x = 0; x <= N - 2; x++)
		{
			for (int y = x; y <= N - 2; y++)
			{
				blockCheck(y, x);
			}
		}

		for (int y = N - 2; y >= 0; y--)
		{
			for (int x = 0; x <= y; x++)
			{
				blockCheck(y, x);
			}
		}

		for (int a = N - 2; a >= 0; a--)
		{
			for (int b = 0; b <= a; b++)
			{
				blockCheck(N - 2 - b, a - b);
			}
		}
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < y + 1; x++)
			{
				cout << block[y][x] << ' ';
			}
			cout << '\n';
		}
	}

	return 0;
}