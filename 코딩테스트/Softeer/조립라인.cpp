#include <iostream>
#include <vector>
using namespace std;

int N;
vector<long long int> ve;

int arr[2][100001];

int main(void)
{
	cin >> N;

	for (int i = 0; i < (4 * (N - 1)) + 2; i++) {
		int num; cin >> num;
		ve.push_back(num);
	}

	arr[0][0] = ve[0];
	arr[1][0] = ve[1];


	int N = 1;

	for (int j = 2; j < ve.size(); j += 4) {
		arr[0][N] = min(arr[0][N - 1] + ve[j + 2], arr[1][N - 1] + ve[j + 1] + ve[j + 2]);
		arr[1][N] = min(arr[1][N - 1] + ve[j + 3], arr[0][N - 1] + ve[j] + ve[j + 3]);
		N++;
	}
	cout << min(arr[0][N-1], arr[1][N-1]);
	
	return 0;
}