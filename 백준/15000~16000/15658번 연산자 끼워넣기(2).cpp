#include <iostream>

using namespace std;

int N;
int A[101];

int Max = -987654321;
int Min = 987654321;

void func(int sum, int index, int plus, int minus, int mul, int div) { // A[0]  1
	if (index == N) {
		Max = max(Max, sum);
		Min = min(Min, sum);
		return;
	}

	if (plus != 0) func(sum + A[index], index + 1, plus - 1, minus, mul, div);
	if (minus != 0) func(sum - A[index], index + 1, plus, minus - 1, mul, div);
	if (mul != 0) func(sum * A[index], index + 1, plus, minus, mul - 1, div);
	if (div != 0) func(sum / A[index], index + 1, plus, minus, mul, div - 1);
}


int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	int plus, minus, mul, div;
	cin >> plus >> minus >> mul >> div;

	func(A[0], 1, plus, minus, mul, div);

	cout << Max << '\n';
	cout << Min << '\n';

	return 0;
}