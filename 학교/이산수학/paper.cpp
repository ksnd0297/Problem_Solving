#include <iostream>
#pragma warning(disable : 4996)

using namespace std;

int T;
int N, M;

int garo[51][51];
int sero[51][51];

int main(void)
{
	freopen("paper.inp", "r", stdin);
	freopen("paper.out", "w", stdout);

	cin >> T;
	while (T--) {
		cin >> N >> M;

		for (int i = 0; i < N; i++) { 
			for (int j = 0; j < M - 1; j++) {
				cin >> sero[i][j];
			}
		}

		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < M; j++) {
				cin >> garo[i][j];
			}
		}

		bool flag = false;
		for (int i = 0; !flag && i < N - 1; i++) {
			for (int j = 0; !flag && j < M - 1; j++) {
				if (garo[i][j] == garo[i][j + 1]) {
					if (sero[i][j] == sero[i + 1][j]) flag = true;
				}
				else if (garo[i][j] != garo[i][j + 1]) {
					if (sero[i][j] != sero[i + 1][j]) flag = true;
				}
			}
		}
		if (!flag) cout << 1 << ' ';
		else cout << 0 << ' ';

	}

	return 0;
}