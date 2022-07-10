#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> ve;

int func(int sum, int index) {
	if (sum == S && index == N) return 1;
	if (index == N) return 0;

	return func(sum + ve[index], index + 1) + func(sum, index + 1);
}

int main(void) {
	cin >> N >> S;
	
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		ve.push_back(num);
	}

	int ans = func(0, 0);
	if (S == 0) ans--;
	cout << ans;

	return 0;
}