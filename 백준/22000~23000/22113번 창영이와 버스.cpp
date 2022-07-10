#include <iostream>
#include <vector>

using namespace std;

int bus[101];
int money[101][101];

int main(void) {
	int N, M; cin >> N >> M;
	for (int i = 0; i < M; i++) cin >> bus[i];
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cin >> money[i][j];

	int sum = 0;
	for (int i = 0; i < M-1; i++) {
		sum += money[bus[i] - 1][bus[i + 1] - 1];
	}
	cout << sum;

	return 0;
}