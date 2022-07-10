#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<string> ve;
string temp;

vector<string> sum;

int main() {
	int N, M; cin >> N >> M;

	for (int i = 0; i < N + M; i++) {
		cin >> temp;
		ve.push_back(temp);
	}

	sort(ve.begin(), ve.end());

	for (int i = 0; i < ve.size() -1; i++) {
		if (ve[i] == ve[i + 1]) {
			sum.push_back(ve[i]); i++;
		}
	}

	cout << sum.size() << endl;
	for (int i = 0; i < sum.size(); i++) cout << sum[i] << endl;
}