#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> list;

int N;
int T, P;

int func(int index, int ans) {
	if (index > N) return 0;
	else if (index == N) return ans;

	return max(func(index + 1, ans), func(index + list[index].first, ans + list[index].second));
}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T >> P;
		list.push_back({ T,P });
	}

	cout << func(0, 0);

	return 0;
}