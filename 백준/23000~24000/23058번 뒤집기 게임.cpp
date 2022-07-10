#include <iostream>

using namespace std;

int map[9][9];
int temp[9][9];
int arr[16];
int N;

void flipheng(int idx) { // 가로 행
	for (int i = 0; i < N; i++) temp[idx][i] *= -1;
}

void flipyel(int idx) { // 세로 열
	for (int i = 0; i < N; i++) temp[i][idx] *= -1;
}

int check() {
	int one = 0; int zero = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (temp[i][j] == 1) one++;
			else if (temp[i][j] == -1) zero++;
		}
	}
	if (one < zero) return one;
	else return zero;
}


int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num; cin >> num;
			if (num == 0) map[i][j] = -1;
			else map[i][j] = 1;
		}
	}
	for (int i = 0; i < N * 2; i++) {
		arr[i] = i;
	}

	int ans = 987654321;

	for (int i = 0; i < (1 << N * 2); ++i) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				temp[i][j] = map[i][j];
			}
		}
		for (int j = 0; j < N * 2; ++j) {
			if (i & (1 << j)) {
				if (j >= 0 && j < N) flipheng(arr[j]);
				else if (j >= N && j < 2 * N) flipyel(arr[j] - N);
				cnt++;
			}
		}
		ans = min(ans, check() + cnt);
	}
	cout << ans;
	return 0;
}