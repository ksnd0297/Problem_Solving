#include <iostream>

using namespace std;

int fence[20001];

int cut(int left, int right) {
	int ret = 0;
	int mid = (left + right) / 2;
	if (left == right) return fence[left]; //길이가 1일 경우 return
	ret = max(cut(left, mid), cut(mid + 1, right));
	int tempL = mid; int tempR = mid + 1;
	int height = 0; int width = 0;

	height = fence[tempL] >= fence[tempR] ? fence[tempL] : fence[tempR];

	while (tempL >= left && tempR <= right) {
		if (fence[tempL] >= fence[tempR]) {
			height = height >= fence[tempL] ? fence[tempL] : height;
			width++; tempL--;
		}
		else if (fence[tempL] < fence[tempR]) {
			height = height >= fence[tempR] ? fence[tempR] : height;
			width++; tempR++;
		}
		ret = max(height * width, ret);
	}

	while (tempR == right + 1 && tempL >= left) { // 오른쪽으로 확대
		height = height >= fence[tempL] ? fence[tempL] : height;
		width++; tempL--;
		ret = max(height * width, ret);
	}
	while (tempL == left - 1 && tempR <= right) {
		height = height >= fence[tempR] ? fence[tempR] : height;
		width++; tempR++;
		ret = max(height * width, ret);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int C; cin >> C;
	while (C--) {
		int N; cin >> N;
		for (int i = 0; i < N; i++) cin >> fence[i];
		cout << cut(0, N - 1) << '\n';
	}
	return 0;
}

