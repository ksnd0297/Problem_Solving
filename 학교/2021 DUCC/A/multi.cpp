#include <fstream>
#include <algorithm>
#include <tuple>
#define ull long long int 

using namespace std;

int T;
int n;

ull arr[100001];

int main(void)
{
	ifstream fin("multi.inp");
	ofstream fout("multi.out");
		
	fin >> T;
	while (T--) {
		fin >> n;
		for (int i = 0; i < n; i++) fin >> arr[i];
		sort(arr, arr + n);

		ull temp0 = arr[0] * arr[1] * arr[2] * arr[3] * arr[4];
		ull temp1 = arr[0] * arr[1] * arr[2] * arr[3] * arr[n - 1];
		ull temp2 = arr[0] * arr[1] * arr[n - 1] * arr[n - 2] * arr[n-3];
		ull temp3 = arr[0] * arr[1] * arr[2] * arr[n - 1] * arr[n - 2];
		ull temp4 = arr[n - 1] * arr[n - 2] * arr[n - 3] * arr[n - 4] * arr[0];
		ull temp5 = arr[n - 1] * arr[n - 2] * arr[n - 3] * arr[n - 4] * arr[n - 5];
		ull maxd = max({ temp0, temp1, temp2, temp3, temp4, temp5 });
		fout << maxd << '\n';
	}
	return 0;
}