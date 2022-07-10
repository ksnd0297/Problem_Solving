#include <iostream>
using namespace std;

double arr[10001];

int main() {
	int N; cin >> N;

	double p = 1.0;  double num;
	for (int i = 0; i < N; i++) {
		cin >> num;  p *= num;
		arr[i] = p;
		if (num == 0.0) p = 1.0;
	}

	double max = 0; int idx = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] == 0) idx = i + 1;
		for (int j = idx; j <= i; j++) {
			if (max < arr[i] / arr[j]) max = arr[i] / arr[j];
		}
	}
	cout.fixed; cout.precision(4);
	cout << max;
	return 0;
}