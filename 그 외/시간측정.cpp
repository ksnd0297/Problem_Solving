#include <iostream>

using namespace std;

int arr[20000][20000];

int main(void)
{
	clock_t start1, start2, end1, end2;

	start1 = clock();
	for (int i = 0; i < 20000; i++) {
		for (int j = 0; j < 20000; j++) {
			arr[j][i] = 1;
		}
	}
	end1 = clock();
	double result1 = (double)(end1 - start1);
	cout << result1 << '\n';
	return 0;
}