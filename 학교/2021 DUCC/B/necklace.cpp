#include <fstream>
#include <algorithm>

using namespace std;

int T;
int n, c0, c1, h;

string arr;

int main(void)
{
	ifstream fin("necklace.inp");
	ofstream fout("necklace.out");

	fin >> T;
	while (T--) {
		fin >> n >> c0 >> c1 >> h;

		int realmoney = 0;
		fin >> arr;
		for (int i = 0; i < n; i++) {
			if (arr[i] == '0') realmoney += c0;
			else realmoney += c1;
		}

		int tempmoney1 = realmoney;
		for (int i = 0; i < n; i++) { // 0 을 1로 바꾸는 경우

			if (arr[i] == '0') {
				tempmoney1 -= c0;
				tempmoney1 += c1;
				tempmoney1 += h;
			}
			if (tempmoney1 > realmoney) break;
		}

		int tempmoney2 = realmoney;
		for (int i = 0; i < n; i++) { // 1 을 0로 바꾸는 경우
			if (arr[i] == '1') {
				tempmoney2 -= c1;
				tempmoney2 += c0;
				tempmoney2 += h;
			}
			if (tempmoney2 > realmoney) break;
		}
		int ans = min({ realmoney, tempmoney1, tempmoney2 });
		fout << ans << '\n';
	}
	fin.close();
	fout.close();
	return 0;
}