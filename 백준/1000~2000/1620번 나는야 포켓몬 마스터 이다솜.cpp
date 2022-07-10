#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> ve;
vector<pair<string, int>> vec;
string temp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		vec.push_back(make_pair(temp, i + 1));
		ve.push_back(temp);
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < M; i++) {
		cin >> temp;
		if (temp[0] - 65 < 0) {
			cout << ve[stoi(temp) - 1] << '\n';
		}
		else {
			int start = 0;
			int end = N - 1;
			while (start <= end) { //정렬 된 상태라면 어떤 형태든 이분탐색이 가능
				int mid = (start + end) / 2;
				if (vec[mid].first == temp) {
					cout << vec[mid].second << '\n';
					break;
				}
				else if (vec[mid].first < temp) {
					start = mid + 1;
				}
				else if (vec[mid].first > temp) {
					end = mid - 1;
				}
			}
		}
	}
}