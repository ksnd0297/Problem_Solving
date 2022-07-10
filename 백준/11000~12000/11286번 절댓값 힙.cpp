#include <iostream>
#include <queue>

using namespace std;

struct cmp {
	bool operator()(int n1, int n2) {
		if (abs(n1) > abs(n2)) return true;
		else if (abs(n1) == abs(n2)) {
			if (n1 > n2) return true;
			else return false;
		}
		return false;
	}
};

priority_queue<int,vector<int>,cmp> pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;
	while (T--) {
		int num; cin >> num;
		if (num == 0) {
			if (pq.empty()) cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else pq.push(num);
	}
	return 0;
}