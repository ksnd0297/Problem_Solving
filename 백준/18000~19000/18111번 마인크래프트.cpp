#include <iostream>

using namespace std;

int arr[501][501];

int main() {
	int N, M, B;
	cin >> N >> M >> B;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int lasttime = INT32_MAX;
	int lasthei = 0;
	for (int hei = 0; hei <= 256; hei++) {
		int del = 0;
		int add = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int height = arr[i][j] - hei;
				if (height > 0) del += arr[i][j] - hei; // 제거해야할 블록의 개수
				else if (height < 0) add += hei - arr[i][j]; // 추가해야할 블록의 개수
			}
		}
		if (del + B >= add) {
			int time = del * 2 + add;
			if (lasttime >= time) {
				lasttime = time;
				lasthei = hei;
			}
		}
	}
	cout << lasttime << ' ' << lasthei << '\n';
}