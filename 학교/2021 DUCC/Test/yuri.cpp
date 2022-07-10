#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

int smallAlpha[26];
int bigAlpha[26];
int T;
string ans;

int main(void)
{
	ifstream fin("yuri.inp");
	ofstream fout("yuri.out");

	fin >> T;
	while (T--) {
		memset(smallAlpha, 0, sizeof(smallAlpha));
		memset(bigAlpha, 0, sizeof(bigAlpha));
		fin >> ans;
		for (int i = 0; i < ans.size(); i++) {
			if (ans[i] >= 65 && ans[i] <= 90) bigAlpha[ans[i] - 65]++;
			else if (ans[i] >= 97 && ans[i] <= 122) smallAlpha[ans[i] - 97]++;
		}
		int smallmax = 0, smallmaxIdx = 0;
		int smallmin = 987654321, smallminIdx = 0;
		int bigmax = 0, bigmaxIdx = 0;
		int bigmin = 987654321, bigminIdx = 0;

		for (int i = 0; i < 26; i++) {
			if (smallmax < smallAlpha[i] && smallAlpha[i] != 0) { smallmax = smallAlpha[i]; smallmaxIdx = i; }
			if (bigmax < bigAlpha[i] && bigAlpha[i] != 0) { bigmax = bigAlpha[i]; bigmaxIdx = i; }
			if (smallmin > smallAlpha[i] && smallAlpha[i] != 0) { smallmin = smallAlpha[i]; smallminIdx = i; }
			if (bigmin > bigAlpha[i] && bigAlpha[i] != 0) { bigmin = bigAlpha[i]; bigminIdx = i; }
		}
		fout << (char)(bigmaxIdx + 65) << ' ' << bigmax << ' ' << (char)(bigminIdx + 65) << ' ' << bigmin << ' '
			<< (char)(smallmaxIdx + 97) << ' ' << smallmax << ' ' << (char)(smallminIdx + 97) << ' ' << smallmin << '\n';
	}

	fin.close();
	fout.close();
	return 0;
}