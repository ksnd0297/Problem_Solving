#include <iostream>
#include <cstring>

using namespace std;

int cache[101][101];
int tri[101][101]; // »ï°¢Çü
int cntt[101][101];
int N; // »ï°¢ÇüÀÇ ±æÀÌ

int path(int y, int x) {
	int& ret = cache[y][x];
	if (y == N - 1) return ret = tri[y][x];
	if (ret != -1) return ret;
	return ret = max(path(y + 1, x), path(y + 1, x + 1)) + tri[y][x];
}

int cnt(int y, int x, int max) {
	int& ret = cntt[y][x];
	if (y == N - 1 && max == cache[y][x]) return ret = 1;
	if (max != cache[y][x]) return 0;
	if (ret != -1) return ret;


	
	return ret = (cnt(y + 1, x, max - tri[y][x]) + cnt(y + 1, x + 1, max - tri[y][x]));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int C; cin >> C;
	while (C--) {
		memset(cache, -1, sizeof(cache));
		memset(cntt, -1, sizeof(cntt));
		cin >> N;
		for (int i = 0; i < N; i++)
			for (int j = 0; j <= i; j++)
				cin >> tri[i][j];
		path(0, 0);
		cout << cnt(0, 0,cache[0][0]) << '\n'; // 0 0 24
	}
	return 0;
}