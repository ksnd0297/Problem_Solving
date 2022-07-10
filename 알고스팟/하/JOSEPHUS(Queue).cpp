#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int temp[2];

int main() {
	int C; cin >> C;
	while (C--) {
		queue<int> jos;
		int N, K; cin >> N >> K;
		for (int i = 1; i <= N; i++) jos.push(i);

		while (jos.size() != 2) {
			jos.pop();
			for (int i = 0; i < K - 1; i++) {
				jos.push(jos.front());
				jos.pop();
			}
		}
		
		for (int i = 0; i < 2; i++) {
			temp[i] = jos.front();
			jos.pop();
		}
		sort(temp, temp + 2);
		cout << temp[0] << ' ' << temp[1] << '\n';
	}
	return 0;
}