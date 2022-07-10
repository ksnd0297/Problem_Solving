#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string str[1001];
pair<int, char> alpha[26];
pair<int, char> moalpha[26];


int main(void)
{
	int C; cin >> C;
	while (C--) {
		int N; cin >> N;
		for (int i = 0; i < N; i++) cin >> str[i];

		for (int i = 0; i < 26; i++) {
			alpha[i].first = i;
			alpha[i].second = i + 'a';
			moalpha[i].first = 27;
			moalpha[i].second = i + 'a';
		}
		moalpha[str[0][0] - 'a'].first = 1;

		bool flag = false; // 모순 유무판단.
		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < str[i].size(); j++) {
				if (str[i][j] != str[i + 1][j]) {
					if (alpha[str[i][j] - 'a'].second >= alpha[str[i + 1][j] - 'a'].second) {
						if(alpha[str[i][j]-'a'].first == alpha[str[i+1][j]-'a'].first) continue;
						else {
							
						}
					}
					else if (alpha[str[i][j] - 'a'].first < alpha[str[i + 1][j]].first) { // 모순 발생
						flag = true;

					}
				}
			}
		}
		if (!flag) for (int i = 0; i < 26; i++) cout << alpha[i].second; // 모순이 발생하지 않음.
		else { // 모순 발생
			sort(alpha + 0, alpha + 26);
			for (int i = 0; i < 26; i++) cout << alpha[i].second;
		}
		cout << '\n';
	}

	return 0;
}