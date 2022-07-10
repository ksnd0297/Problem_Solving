#include <iostream>
#include <fstream>

using namespace std;

int T;
int a, b, c, d;

int main(void)
{
	ifstream fin("multiple.inp");
	ofstream fout("multiple.out");

	fin >> T;
	while (T--) {
		fin >> a >> b >> c >> d;
		int ans = 0;
		for (int i = a; i <= b; i++) {
			if (i % c == 0 || i % d == 0) ans++;
		}
		fout << ans << '\n';
	}

	fin.close();
	fout.close();
	return 0;
}