#include <iostream>
#include <queue>
#pragma warning(disable: 4996)

using namespace std;


priority_queue<int> maxpq, minpq;

int N;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;

		if (maxpq.size() <= minpq.size()) maxpq.push(num);
		else if (maxpq.size() > minpq.size()) minpq.push(-num);

		if (maxpq.size() != 0 && minpq.size() != 0)
			if (maxpq.top() > -minpq.top()) {
				int minNum = -minpq.top(); minpq.pop();
				int maxNum = maxpq.top(); maxpq.pop();
				minpq.push(-maxNum); maxpq.push(minNum);
			}

		cout << maxpq.top() << '\n';
	}
	return 0;
}