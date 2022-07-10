#include <iostream>
#include <string>
#include <string.h>

using namespace std;


string secret[8] = { "000000","001111","010011","011100","100110","101001","110101","111010" };

int N;
string qus, ans;
int match[8];

int main(void)
{
	cin >> N;
	cin >> qus;

	for (int i = 0; i < qus.size(); i += 6) {
		for (int j = 0; j < 8; j++) {
			if (qus[i] == secret[j][0]) match[j]++;
			if (qus[i + 1] == secret[j][1]) match[j]++;
			if (qus[i + 2] == secret[j][2]) match[j]++;
			if (qus[i + 3] == secret[j][3]) match[j]++;
			if (qus[i + 4] == secret[j][4]) match[j]++;
			if (qus[i + 5] == secret[j][5]) match[j]++;
		}

		bool flag = false;
		for (int k = 0; !flag && k < 8; k++) {
			if (match[k] == 6) {
				flag = true;
				ans.push_back(k + 65);
			}
		}
		if (!flag) { // 완전 매칭되는 문자가 없음
			bool flag2 = false;
			for (int k = 0; !flag2 && k < 8; k++) {
				if (match[k] == 5) {
					flag2 = true;
					ans.push_back(k + 65);
				}
			}

			if (!flag2) { // 5개 매칭되는 문자가 없음
				cout << (i / 6) + 1;
				return 0;
			}
		}
		memset(match, 0, sizeof(match));
	}
	cout << ans;
	return 0;
}