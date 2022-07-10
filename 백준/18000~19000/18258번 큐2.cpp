#include <iostream>
#include <queue>

using namespace std;

int N;
string ope; // operator
int opr;  // operand

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	queue<int> q;
	while (N--) {
		cin >> ope;
		if (ope == "push") {
			cin >> opr; 
			q.push(opr);
		}

		else if (ope == "pop") {
			if (!q.empty()) {
				cout << q.front() << '\n';
				q.pop();
			}
			else cout << -1 << '\n';
		}

		else if (ope == "size") {
			cout << q.size() << '\n';
		}

		else if (ope == "empty") {
			if (q.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}

		else if (ope == "front") {
			if (q.empty()) cout << -1 << '\n';
			else cout << q.front() << '\n';
		}

		else if (ope == "back") {
			if (q.empty()) cout << -1 << '\n';
			else cout << q.back() << '\n';
		}
	}

	return 0;
}