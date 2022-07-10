#include <iostream>

using namespace std;

int fri[101][101];

int main() {
	int N, M; cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			fri[i][j] = 123456789; // 갈 수 없는 길 123456789
		}
	}

	int A, B;
	for (int i = 0; i < M; i++) {
		cin >> A >> B; fri[A][B] = 1; fri[B][A] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) continue; // 같은 위치 패스
				if (fri[i][j] > fri[i][k] + fri[k][j]) fri[i][j] = fri[i][k] + fri[k][j];
			}
		}
	}
	int min = 123456789;
	int index = 0;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			if (i != j) sum += fri[i][j];
		}
		if (min > sum) {
			min = sum; index = i;
		}
	}
	cout << index;


	return 0;
}