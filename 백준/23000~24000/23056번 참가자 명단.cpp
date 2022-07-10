#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
	if (a.length() < b.length()) return 1;
	else if (a.length() > b.length()) return 0;
	else return a < b;
}

vector<string> cls[11];
int N, M;

int main(void)
{
	cin >> N >> M;
	while (1) {
		int a; string b;
		cin >> a >> b;
		if (a == 0 && b == "0") break;
		if (cls[a].size() < M) cls[a].push_back(b);
	}

	for (int i = 1; i <= N; i++) {
		sort(cls[i].begin(), cls[i].end(), compare);
	}

	for (int i = 1; i <= N; i += 2) {
		for (int j = 0; j < cls[i].size(); j++) {
			cout << i << ' ' << cls[i][j] << '\n';
		}
	}

	for (int i = 2; i <= N; i += 2) {
		for (int j = 0; j < cls[i].size(); j++) {
			cout << i << ' ' << cls[i][j] << '\n';
		}
	}

	return 0;
}