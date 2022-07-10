#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> num;
bool check[10001];

void func(vector<int>& ve, int index)
{
	if (ve.size() == M) {
		for (int i = 0; i < ve.size(); i++) cout << ve[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = index; i < N; i++) {
		if (!check[num[i]])
		{
			check[num[i]] = true; ve.push_back(num[i]);
			func(ve, i + 1);
			check[num[i]] = false; ve.pop_back();
		}
	}
}

int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int temp; cin >> temp;
		num.push_back(temp);
	}
	sort(num.begin(), num.end());

	vector<int> ve;
	func(ve, 0);

	return 0;
}