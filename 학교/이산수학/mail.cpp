#include <iostream>
#include <string>
#include <cstring>
#pragma warning(disable : 4996)
#define INF 987654321

using namespace std;

string alpha[8] = {
	{"000000"},
	{"001111"},
	{"010011"},
	{"011100"},
	{"100110"},
	{"101001"},
	{"110101"},
	{"111010"}
};

int check[8];

int T;
int N; string str;

int main(void)
{
	freopen("mail.inp", "r", stdin);
	freopen("mail.out", "w", stdout);

	cin >> T;
	while (T--) {
		cin >> N;
		cin >> str;
		for (int i = 0; i < str.size(); i += 6) {
			memset(check, 0, sizeof(check));
			string temp = str.substr(i, 6);
			for (int j = 0; j < 8; j++) {
				for (int k = 0; k < alpha[j].size(); k++) {
					if (temp[k] != alpha[j][k]) check[j]++;
				}
			}

			int min = INF;
			int index = 0;
			for (int i = 0; i < 8; i++) {
				if (min > check[i]) {
					min = check[i];
					index = i;
				}
			}

			if (min >= 2) cout << 'X';
			else cout << (char)(index + 'A');
		}
		cout << '\n';
	}
}