#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main(void) {
	while (1) {
		cin >> N;
		if (N == 0) break;

		vector<int> ve;
		for (int i = 0; i < N; i++) {
			int num; cin >> num;
			ve.push_back(num);
		}
		sort(ve.begin(), ve.end());

		int sum = ve[0] + ve[1];
		for (int i = 2; i < ve.size(); i++) {
			sum += (sum + ve[i]);
		}
		cout << sum << '\n';
	}

	return 0;
}