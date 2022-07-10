#include <fstream>

using namespace std;

int T;
int n, w;
int arr[10001];

int main(void)
{
	ifstream fin("drivethru.inp");
	ofstream fout("drivethru.out");
	fin >> T;
	while (T--) {
		fin >> n >> w;
		for (int i = 0; i < n; i++) fin >> arr[i];
		
		int max = 0;
		int index = 0;
		for (int i = w - 1; i < n; i++) {
			int temp = 0;
			for (int j = i; j > i - w; j--) {
				temp += arr[j];
			}
			if (max < temp) {
				max = temp;
				index = i + 1;
			}
		}
		fout << index << ' ' << max << '\n';
	}
	fin.close();
	fout.close();
	return 0;
}