#include <iostream>
#include <queue>

using namespace std;
int C, K, N;

struct RNG {
	unsigned seed;
	RNG() : seed(1983) {}
	unsigned next() {
		unsigned ret = seed;
		seed = ((seed * 214013u) + 2531011u);
		return ret % 10000 + 1;
	}
};

int countRanges(int k, int n) {
	RNG rng; // 신호값을 생성하는 난수 생성기
	queue<int> range; // 현재 구간에 들어 있는 숫자들을 저장하는 큐
	int ret = 0, rangeSum = 0;
	for (int i = 0; i < n; i++) {
		int newSignal = rng.next();
		rangeSum += newSignal;
		range.push(newSignal);

		while (rangeSum > k) {
			rangeSum -= range.front();
			range.pop();
		}
		if (rangeSum == k) ret++;
	}
	return ret;
}

int main(void)
{
	cin >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> K >> N;
		cout << countRanges(K, N) << endl;
	}
	return 0;
}