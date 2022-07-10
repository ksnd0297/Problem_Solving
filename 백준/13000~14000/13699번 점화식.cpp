#include <iostream>

using namespace std;

long long int T[35];

int main(void)
{
	T[0] = 1;
	T[1] = 1;
	T[2] = 2;
	T[3] = 5;


	int N; cin >> N;
	for (int i = 4; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			T[i] += T[j] * T[i - j -1];
		}
	}
	cout << T[N];
	return 0;
}