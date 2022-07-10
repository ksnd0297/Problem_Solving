#include <iostream>

using namespace std;

int gcd(int A, int B) {
	if (A < B) return gcd(B, A);
	return B == 0 ? A : gcd(B, A % B);
}

int t;
int n;
int arr[101];

int main(void)
{
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> arr[i];
		
		long long int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ans += gcd(arr[i], arr[j]);
			}
		}
		cout << ans << '\n';
	}

	return 0;
}