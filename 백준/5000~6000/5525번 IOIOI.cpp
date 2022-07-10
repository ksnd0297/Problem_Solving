#include <iostream>
#include <vector>

using namespace std;

char P[2000002]; // IOI ...
char S[2000002]; // OOIOIOIOIIOII

vector<int> getPi(string p) {
	int m = (int)p.size(), j = 0;
	vector<int>Pi(m, 0);
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j]) j = Pi[i - 1];
		if (p[i] == p[j]) Pi[i] = ++j;
	}
	return Pi;
}

int kmp(string s, string p) {
	int cnt = 0;
	auto Pi = getPi(p);
	int n = (int)s.size(), m = (int)p.size(), j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j]) j = Pi[j - 1];
		if (s[i] == p[j]) {
			if (j == m - 1) {
				cnt++; j = Pi[j];
			}
			else j++;
		}
	}
	return cnt;
}

int main() {
	int N, M; cin >> N >> M;
	P[0] = 'I';
	int pos = 1;
	while (N--) { P[pos++] = 'O'; P[pos++] = 'I'; } // IOI를 만드는 연산

	for (int i = 0; i < M; i++) cin >> S[i];

	cout << kmp(S, P);
	return 0;
}