#include <iostream>
#include <algorithm>

using namespace std;

int MinDp[3], MaxTemp[3];
int MaxDp[3], MinTemp[3];

int arr[3];
int N;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) cin >> arr[j];

		MaxTemp[0] = max(MaxDp[0], MaxDp[1]) + arr[0];
		MaxTemp[1] = max({ MaxDp[0], MaxDp[1], MaxDp[2] }) + arr[1];
		MaxTemp[2] = max(MaxDp[1], MaxDp[2]) + arr[2];

		MinTemp[0] = min(MinDp[0], MinDp[1]) + arr[0];
		MinTemp[1] = min({ MinDp[0], MinDp[1], MinDp[2] }) + arr[1];
		MinTemp[2] = min(MinDp[1], MinDp[2]) + arr[2];

		MaxDp[0] = MaxTemp[0]; MaxDp[1] = MaxTemp[1]; MaxDp[2] = MaxTemp[2];
		MinDp[0] = MinTemp[0]; MinDp[1] = MinTemp[1]; MinDp[2] = MinTemp[2];
	}

	cout << max({ MaxDp[0], MaxDp[1], MaxDp[2] }) << ' ' << min({ MinDp[0], MinDp[1], MinDp[2] });

	return 0;
}