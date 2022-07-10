#include <iostream>
#include <vector>

using namespace std;

int N, K;

int money[1000001];
vector<int> medo;

int bSearch(int start, int end) { // N  && K /N
	int mid = (start + end) / 2;
	
	for (int i = 0; i < medo.size(); i++) money[medo[i]] = mid;

	int sum = 0;
	for (int i = 1; i < mid + medo[medo.size() - 1]; i++) {
		if (money[i - 1] != 0 && money[i-1] != N) money[i] = money[i - 1] - 1;
	}

	if (sum < K) return bSearch(mid + 1, end);
	return mid;
}

int main(void) {
	cin >> N >> K;
	if (N >= K) {
		cout << 1;
		return 0;
	}

	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		medo.push_back(num);
	}
	cout << bSearch(N, K / N);

	return 0;
}