#include <iostream>
#include <vector>
#define ull unsigned long long int

using namespace std;

vector<int> coin;

int n, k;

int func(int Num) {
	if (Num == 0) return 1;
	if (Num < 0) return 0;

	int ans = 0;
	for (int i = 0; i < coin.size(); i++) {
		ans += func(Num - coin[i]);
	}
	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int Num; cin >> Num;
		coin.push_back(Num);
	}

	cout << func(k);

	return 0;
}