#include <fstream>
#include <string>

using namespace std;

int T;

int main(void)
{
	ifstream fin("alphabet.inp");
	ofstream fout("alphabet.out");

	fin >> T;
	while (T--) {
		string ans; fin >> ans;
		if (ans.size() == 1 && ans[0] == 'a') {
			fout << "YES" << '\n'; continue;
		}
		int idx = 0;
		bool flag = false;
		for (int i = 0; i < ans.size(); i++) {
			if (ans[i] == 'a') {
				flag = true; idx = i; break;
			}
		}
		if (!flag) {
			fout << "NO" << '\n'; continue;
		}

		int idxleft = idx - 1;
		int idxright = idx + 1;
		int check = 'b';
		flag = false;
		while (1) {
			if (idxleft == -1 && idxright == ans.size()) break;
			if (idxleft != -1 && check == (int)ans[idxleft]) {
				idxleft--; check++;
			}
			else if (idxright != ans.size() && check == (int)ans[idxright]) {
				idxright++; check++;
			}
			else break;
		}
		check - ans.size() != 'a' ? fout << "NO" << '\n' : fout << "YES" << '\n';
	}
	return 0;
}