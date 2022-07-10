#include <iostream>
#include <cstring>

using namespace std;

int tri[101][101];
int cache[101][101];
int N;

int path(int y, int x) {
	int& ret = cache[y][x];
	if (ret != -1) return ret;
	if (y == N - 1) return ret = tri[y][x];
	return ret = max(path(y + 1, x), path(y + 1, x + 1)) + tri[y][x];
}

int main() {
	int C; cin >> C;
	while (C--) {
		cin >> N;
		for (int i = 0; i < N; i++)
			for (int j = 0; j <= i; j++)
				cin >> tri[i][j];
		memset(cache, -1, sizeof(cache));
		cout << path(0, 0) << '\n';
	}
	return 0;
}