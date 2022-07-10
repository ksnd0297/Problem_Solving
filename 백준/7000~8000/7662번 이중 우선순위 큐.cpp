#include <iostream>
#include <queue>

using namespace std;

bool hashed[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;
	while (T--) {
		priority_queue < pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> maxpq;
		priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minpq;

		int N; cin >> N;
		for (int i = 0; i < N; i++) {
			char ch; int num;
			cin >> ch >> num;
			if (ch == 'I') {
				maxpq.push({ num,i }); minpq.push({ num,i }); // 
				hashed[i] = true;
			}
			else if (ch == 'D' && num == -1) {
				while (!minpq.empty() && !hashed[minpq.top().second]) minpq.pop();
				if (!minpq.empty()) {
					hashed[minpq.top().second] = false;
					minpq.pop();
				}
			}
			else if (ch == 'D' && num == 1) {
				while (!maxpq.empty() && !hashed[maxpq.top().second]) maxpq.pop();
				if (!maxpq.empty()) {
					hashed[maxpq.top().second] = false;
					maxpq.pop();
				}
			}

			while (!maxpq.empty() && !hashed[maxpq.top().second]) maxpq.pop();
			while (!minpq.empty() && !hashed[minpq.top().second]) minpq.pop();
		}
		if (maxpq.empty() && minpq.empty()) cout << "EMPTY\n";
		else cout << maxpq.top().first << ' ' << minpq.top().first << '\n';
	}
	return 0;
}