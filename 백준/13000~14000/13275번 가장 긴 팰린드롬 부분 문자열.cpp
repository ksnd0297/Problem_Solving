#include <iostream>
#include <string>

using namespace std;

int A[200001];

void manachers(string S, int N)
{
	int r = 0, p = 0;
	for (int i = 0; i < N; i++) {
		if (i <= r) A[i] = min(A[2 * p - i], r - i);
		else A[i] = 0;
		while (i - A[i] - 1 >= 0 && i + A[i] + 1 < N && S[i - A[i] - 1] == S[i + A[i] + 1]) A[i]++;

		if (r < i + A[i]) {
			r = i + A[i];
			p = i;
		}
	}
}

int main(void)
{
	string qus; cin >> qus;

	string ans = "";

	for (int i = 0; i < qus.size(); i++) {
		ans.append("#");
		ans.push_back(qus[i]);
	}
	ans.append("#");

	manachers(ans, ans.size());

	int ret = 0;
	for (int i = 0; i < ans.size(); i++) {
		if (ret < A[i]) ret = A[i];
	}
	cout << ret;
	return 0;
}