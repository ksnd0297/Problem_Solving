#include <iostream>
#include <vector>

using namespace std;

vector<int> multiply(vector<int>& a, vector<int>& b) {
	vector<int> c(a.size() + b.size() + 1, 0);
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			c[i + j] += a[i] * b[j];
		}
	}
	return c;
}

void move(int from, int to) {
	cout << from << ' ' << to << '\n';
}

void hanoi(int n, int from, int by, int to) {
	if (n == 1) {
		move(from, to);
	}
	else {
		hanoi(n - 1, from, to, by);
		move(from, to);
		hanoi(n - 1, by, from, to);
	}
}

int main() {
	int N; cin >> N;
	string ans = "2";
	
	if (N <= 20)
		hanoi(N, 1, 2, 3);

	return 0;
}