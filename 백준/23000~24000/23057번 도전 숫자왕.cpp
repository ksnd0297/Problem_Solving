#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int N;
int arr[21];
set<int> se;
vector<int> ve;

void rec(int index, int sum) {
	if (index > N) return;
	se.insert(sum);
	rec(index + 1, sum + arr[index]);
	rec(index + 1, sum);
}


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	int sum = 0;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	rec(0, 0);

	set<int>::iterator iter;
	for (iter = se.begin(); iter != se.end(); iter++) {
		ve.push_back(*iter);
	}

	for (int i = 0; i < ve.size() - 1; i++) {
		ans += ve[i + 1] - ve[i] - 1;
	}


	cout << ans;

	return 0;
}