#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string s, t;

int main(void)
{
	ifstream fin("backspace.inp");
	ofstream fout("backspace.out");

	int T; fin >> T;
	while (T--) {
		fin >> s >> t;
		bool flag = false;
		int tIndex = 0;
		if (t.size() > s.size()) {
			fout << "NO" << '\n'; continue;
		}
		for (int i = 0; !flag && i < s.size() - t.size() + 1; i++) {
			if (s[i] == t[tIndex]) {
				tIndex++;
				int j = i + 1;
				for (; !flag && j < s.size();) {
					if (s[j] == t[tIndex]) { tIndex++; j++; }
					else j += 2;

					if (tIndex == t.size() && j == s.size()) {
						flag = true; fout << "YES" << '\n';
					}
				}
				tIndex = 0;
			}
		}
		if (!flag) fout << "NO" << '\n';
	}

	fin.close();
	fout.close();
	return 0;
}