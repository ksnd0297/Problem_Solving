#include <iostream>
#include <math.h>

using namespace std;

int A, B, V;

int main(void)
{
	cin >> A >> B >> V;
	int ans = 1;
	if (V - A <= 0) { cout << 1; return 0; }
	ans += (int)ceil((V - A) / (double)(A - B));
	cout << ans;
	return 0;
}