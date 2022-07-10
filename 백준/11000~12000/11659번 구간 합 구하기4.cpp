#include <iostream>

using namespace std;

int arr[100001];
int sum[100001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M; cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> arr[i];

	sum[1] = arr[1];
	for (int i = 2; i <= N; i++) sum[i] = sum[i - 1] + arr[i];

	int A, B;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		cout << sum[B] - sum[A-1] << '\n';
	}

	return 0;
}