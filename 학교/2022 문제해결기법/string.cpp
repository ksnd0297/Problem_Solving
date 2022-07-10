#include <iostream>
#include <algorithm>
#include <string>
#pragma warning(disable : 4996)

using namespace std;

int T;
string S;

int main(void)
{
	freopen("string.inp", "r", stdin);
	freopen("string.out", "w", stdout);

	cin >> T;
	while (T--) {
		cin >> S;
		string temp = S;
		if (prev_permutation(S.begin(), S.end())) cout << S << ' ';
		else cout << -1 << ' ';


		if (next_permutation(temp.begin(), temp.end())) cout  << temp;
		else cout << -1;
		
		cout << '\n';
	}
	return 0;
}