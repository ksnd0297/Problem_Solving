#include <iostream>
#include <cstring>

using namespace std;

long long int f[91];

long long int fibo(int N) {
	if (N == 0) return 0;
	if (N == 1)	return 1;
	long long int& ret = f[N];
	if (ret != -1) return ret;
	return ret = fibo(N - 1) + fibo(N - 2);
}

int main() {
	int N; cin >> N;
	memset(f, -1, sizeof(f));
	cout << fibo(N);

	return 0;
}