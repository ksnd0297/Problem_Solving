#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> num;
int check[10001];

void func(vector<int>& ve, int index)
{
	if (ve.size() == M) {
		for (int i = 0; i < ve.size(); i++) cout << ve[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < num.size(); i++) {
		ve.push_back(num[i]);
		func(ve, i);
		ve.pop_back();
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

	for (int i = 0; i < num.size(); i++) check[num[i]]++;

	num.erase(unique(num.begin(), num.end()), num.end());

	vector<int> ve;
	func(ve, 0);

	return 0;
}