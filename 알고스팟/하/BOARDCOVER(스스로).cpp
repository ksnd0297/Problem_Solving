#include <iostream>

using namespace std;

int C, H, W;

int map[21][21];
int block[4][3][2] = {
					{{0,0}, {1,0}, {1,1}},
					{{0,0}, {0,1}, {1,1}},
					{{0,0}, {0,1}, {1,0}},
					{{0,0}, {1,0}, {1,-1}}
};

int go() {
	int y = -1, x = -1;
	for (int i = 0; y == -1 && i < H; i++) {
		for (int j = 0; y == -1 && j < W; j++)
			if (map[i][j] == 0) {
				y = i; x = j;
			}
	}

	if (y == -1) return 1;
	int ret = 0;

	for (int k = 0; k < 4; k++) {
		bool flag = false;
		for (int l = 0; !flag && l < 3; l++) {
			int tempY = y + block[k][l][0];
			int tempX = x + block[k][l][1];
			if (!(tempY >= 0 && tempY < H && tempX >= 0 && tempX < W) || map[tempY][tempX]) flag = true;
		}
		if (!flag) {
			for (int l = 0; l < 3; l++) map[y + block[k][l][0]][x + block[k][l][1]] = 1;
			ret += go();
			for (int l = 0; l < 3; l++) map[y + block[k][l][0]][x + block[k][l][1]] = 0;
		}
	}
	return ret;
}

int main(void)
{
	cin >> C;
	while (C--) {
		cin >> H >> W;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				char ch; cin >> ch;
				if (ch == '#') map[i][j] = 1;
				else map[i][j] = 0;
			}
		}
		cout << go() << '\n';
	}
	return 0;
}