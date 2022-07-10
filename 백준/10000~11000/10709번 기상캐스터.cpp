#include <iostream>

using namespace std;

char ch;
int groom[101][101];

int main(void) {
	int H, W; cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> ch;
			if (ch == 99) groom[i][j] = 0;
			else groom[i][j] = -1;
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 1; j < W; j++) {
			if(groom[i][j] == -1 && groom[i][j-1] != -1)groom[i][j] = groom[i][j - 1] + 1;
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << groom[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}