#include <iostream>

using namespace std;

int map[1010][1010];

int N;

int ans[101];

int main(void)
{
	cin >> N;
	int A, B, C, D;
	for (int k = 1; k <= N; k++) {
		cin >> A >> B >> C >> D;
		for (int i = A; i < A + C; i++) {
			for (int j = B; j < B + D; j++) {
				map[i][j] = k;
			}
		}
	}

	for (int i = 0; i < 1010; i++) {
		for (int j = 0; j < 1010; j++) {
			ans[map[i][j]]++;
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}