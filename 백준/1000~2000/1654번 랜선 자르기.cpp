#include <iostream>

using namespace std;

long long int arr[10001];
int K, N;

bool check(long long int mid) {
	long long int count = 0;
	for (int i = 0; i < K; i++) {
		count += (arr[i] / mid);
	}
	if (count >= N) return 1;
	else return 0;
}

int main() {
	cin >> K >> N;

	long long int max = 0;
	for (int i = 0; i < K; i++) {
		cin >> arr[i];
		if (max < arr[i]) max = arr[i];
	}

	long long int start = 0;//최소 값 가장 긴 선에서 11개 얻기
	long long int end = max; //최대 값 
	long long int result = 0;
	while (start  <= end) {
		long long int mid = (start + end) / 2;

		if (check(mid)) {
			result = mid;
			start = mid+1;
		}
		else {
			end = mid-1;
		}
	}
	cout << result;
}