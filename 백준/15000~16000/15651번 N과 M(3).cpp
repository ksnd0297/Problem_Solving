#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<int> num;

void func(vector<int>& ve)
{
	if (ve.size() == M) {
		for (int i = 0; i < ve.size(); i++) cout << ve[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		ve.push_back(num[i]);
		func(ve);
		ve.pop_back();
	}
}

int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) num.push_back(i + 1);


	vector<int> ve;
	func(ve);

	return 0;
}