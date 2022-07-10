#include <iostream>
#include <algorithm>

using namespace std;

int M, N;

int map[701][701];

int arr[701];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;

	for (int i = 0; i < 2 * M - 1; i++) arr[i] = 1;

	for (int i = 0; i < N; i++) {
		int a, b, c; cin >> a >> b >> c;

		for (int j = a; j < a + b; j++) arr[j]++;
		for (int j = a + b; j < a + b + c; j++) arr[j] += 2;
	}

	// 중간을 기준으로 <- 0 열,  ->  0행
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			if (j == 0) cout << arr[M - i - 1] << ' ';
			else cout << arr[M + j - 1] << ' ';
		}
		cout << '\n';
	}

	return 0;
}