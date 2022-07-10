#include <iostream>
#define MAX(x,y) (x>y)?(x):(y)

using namespace std;

long long int arr[1000001];
int N, M;

bool check(long long int cut) {
	long long int sum = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] - cut > 0) sum += (arr[i] - cut);
	}
	if (sum >= M) return 1;
	else return 0;
}

int main() {
	cin >> N >> M;

	long long int max = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		max = MAX(max, arr[i]);
	}
	
	long long int start = 0;
	long long int end = max;
	long long int result;

	while (start <= end) {
		long long int mid = (start + end) / 2;

		if (check(mid)) {
			result = mid;
			start = mid + 1;
		}
		else end = mid - 1;
	}
	cout << result;
}