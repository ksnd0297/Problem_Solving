#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> c;

vector<pair<int, int>> sale[11]; // 물약 세일 정보 i 번 무얅 구매 시 물약 a가 동전 d 만큼 할인

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		c.push_back(num);
	}

	for (int i = 0; i < N; i++) {
		int P; cin >> P;
		for (int j = 0; j < P; j++) {
			int a, d; cin >> a >> d;
			sale[i].push_back({ a - 1,d });
		}
	}

	vector<int> pe;
	for (int i = 0; i < N; i++) pe.push_back(i);

	int ans = 987654321;
	do {
		int sum = 0;
		vector<int> temp = c; // 임의로 담을 배열
		for (int i = 0; i < pe.size(); i++) {
			sum += temp[pe[i]];
			for (int j = 0; j < sale[pe[i]].size(); j++) {
				int saleItem, saleMoney;
				saleItem = sale[pe[i]][j].first;
				saleMoney = sale[pe[i]][j].second;
				temp[saleItem] -= saleMoney;
				if (temp[saleItem] < 0) temp[saleItem] = 1;
			}
		}

		ans = min(ans, sum);

	} while (next_permutation(pe.begin(), pe.end()));
	cout << ans;

	return 0;
}