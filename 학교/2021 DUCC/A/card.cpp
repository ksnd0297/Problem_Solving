#include <fstream>
#include <algorithm>
#include <vector>
#include <string.h>
#define ull unsigned long long int

using namespace std;

int T;
ull n, k, x; // 인적한 값 x 이하 그룹 묶기 가능
ull arr[100001];


int main(void)
{
	ifstream fin("card.inp");
	ofstream fout("card.out");

	fin >> T;
	while (T--) {
		vector<ull> gap;
		vector<ull> needcard;
		fin >> n >> k >> x; // k : 백지카드 개수 x : 갭
		for (int i = 0; i < n; i++) fin >> arr[i];
		sort(arr, arr + n);

		int ans = 1;
		for (int i = 1; i < n; i++) {
			if (arr[i] - arr[i - 1] > x) {
				gap.push_back(arr[i] - arr[i - 1]);
				ans++;
			}
		}
		sort(gap.begin(), gap.end());

		// k : 백지카드 개수
		if (x != 0) {
			for (int i = 0; i < gap.size(); i++) {
				if (gap[i] % x == 0) {
					needcard.push_back(gap[i] / x - 1);
				}
				else {
					needcard.push_back(gap[i] / x);
				}
			}
		}
		for (int i = 0; i < needcard.size(); i++) {
			if (needcard[i] <= k) {
				k -= needcard[i];
				ans--;
			}
		}
		fout << ans << '\n';
	}

	return 0;
}