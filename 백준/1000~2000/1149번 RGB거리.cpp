#include <iostream>

long long int house[3][1001];
long long int cache[3][1001];

using namespace std;


int main(void) {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> house[j][i];
		}
	}
	cache[0][0] = house[0][0]; cache[1][0] = house[1][0]; cache[2][0] = house[2][0];
	for (int i = 1; i < N; i++) {
		cache[0][i] = min(cache[1][i - 1], cache[2][i - 1]) + house[0][i];
		cache[1][i] = min(cache[0][i - 1], cache[2][i - 1]) + house[1][i];
		cache[2][i] = min(cache[0][i - 1], cache[1][i - 1]) + house[2][i];
	}

	long long int min = INT64_MAX;
	for (int i = 0; i < 3; i++) {
		if (min > cache[i][N - 1]) min = cache[i][N - 1];
	}
	cout << min;
	return 0;
}