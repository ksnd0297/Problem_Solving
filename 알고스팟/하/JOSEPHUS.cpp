#include <iostream>
#include <list>

using namespace std;

int main() {
	int C; cin >> C;
	while (C--) {
		int N, K; cin >> N >> K;
		list<int> li;

		for (int i = 1; i <= N; i++) li.push_back(i);


		list<int>::iterator begin_iter = li.begin(); // Ã³À½ 
		while (li.size() > 2) {
			begin_iter = li.erase(begin_iter);
			if (begin_iter == li.end()) begin_iter = li.begin();
			for (int i = 0; i < K - 1; i++) {
				begin_iter++;
				if (begin_iter == li.end()) begin_iter = li.begin();
			}
		}

		for (int i = 0; i < 2; i++) {
			cout << li.front() << ' '; li.pop_front();
		}
		cout << '\n';
	}
	return 0;
}