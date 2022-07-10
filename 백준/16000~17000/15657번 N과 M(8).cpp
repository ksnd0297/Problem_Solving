#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> num;

void func(vector<int>& ve, int index)
{
	if (ve.size() == M) {
		for (int i = 0; i < ve.size(); i++) cout << ve[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = index; i < N; i++) {
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

	vector<int> ve;
	func(ve, 0);

	return 0;
}