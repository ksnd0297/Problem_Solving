#include <fstream>

using namespace std;

int T;
int n;
int arr[10001];

int main(void)
{
	ifstream fin("building.inp");
	ofstream fout("building.out");

	fin >> T;
	while (T--) {
		fin >> n;
		for (int i = 0; i < n; i++) fin >> arr[i];

		int ans = 0;
		for (int i = 0; i < n-1; i++) {
			int max = 0;
			for (int j = i + 1; j < n; j++) {
				if (max > arr[i] || max > arr[j]) continue;
				if (max < arr[j]) {
					max = arr[j]; ans++;
				}
				else ans++;
			}
		}
		fout << ans << '\n';
	}
	return 0;
}