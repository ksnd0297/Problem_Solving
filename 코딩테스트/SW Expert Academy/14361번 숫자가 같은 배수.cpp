#include <bits/stdc++.h>
using namespace std;

int T;
int N; string str;

int main(void) {
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cin >> N; str = to_string(N);
		sort(str.begin(), str.end());

		bool flag = false;
		do {
			int Num = stoi(str);
			if (Num / N > 1 && Num % N == 0) flag = true;
		} while (!flag && next_permutation(str.begin(), str.end()));

		cout << "#" << i;
		flag == 0 ? cout << " impossible" : cout << " possible";
		cout << '\n';
	}
	return 0;
}