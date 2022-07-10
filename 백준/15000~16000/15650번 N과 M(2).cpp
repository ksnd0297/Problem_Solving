#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<int> num;
bool check[9];

void func(vector<int>& ve, int index) {
	if (ve.size() == M) {
		for (int i = 0; i < ve.size(); i++) cout << ve[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = index; i < num.size(); i++) {
		if (!check[i]) {
			check[i] = true; ve.push_back(num[i]);
			func(ve, i + 1);
			check[i] = false; ve.pop_back();
		}
	}
}

int main(void)
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++) num.push_back(i);

	vector<int> ve;
	func(ve, 0);

	return 0;
}