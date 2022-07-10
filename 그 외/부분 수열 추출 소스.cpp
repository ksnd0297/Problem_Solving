#include <iostream> 
using namespace std;
int main()
{
	int i, j; 
	int arr[16];
	int N;
	cin >> N;
	for (int i = 0; i < 2*N; i++) {
		arr[i] = i;
	}
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++)
			if (i & (1 << j)) {
				cout << arr[j] << " ";
			}
		cout << endl;
	}
	return 0;
}
