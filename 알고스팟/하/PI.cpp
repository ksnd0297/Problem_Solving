#include <iostream>
#include <cstring>

using namespace std;

int cache[10001];
const int INF = 987654321;
string N;

int classfiy(int a, int b) {
	string M = N.substr(a, b - a + 1);
	if (M == string(M.size(), M[0])) return 1;

	bool progressive = true;
	for (int i = 0; i < M.size() - 1; i++) 
		if (M[i + 1] - M[i] != M[1] - M[0]) progressive = false;
	if (progressive && abs(M[1] - M[0]) == 1) return 2;

	bool alternating = true;
	for (int i = 0; i < M.size(); i++)
		if (M[i] != M[i % 2]) alternating = false;
	if (alternating) return 4;
	if (progressive) return 5;
	return 10;
}

int memorize(int begin) {
	if (begin == N.size()) return 0;

	int& ret = cache[begin];
	if (ret != -1) return ret;

	ret = INF;
	for (int L = 3; L <= 5; L++) 
		if (begin + L <= N.size()) ret = min(ret, memorize(begin + L) + classfiy(begin, begin + L - 1));
	return ret;
}


int main() {
	int C; cin >> C;
	while (C--) {
		cin >> N;
		memset(cache, -1, sizeof(cache));
		cout << memorize(0) << '\n';
		}
	return 0;
}