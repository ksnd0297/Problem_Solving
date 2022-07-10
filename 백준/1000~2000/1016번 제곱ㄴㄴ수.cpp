#include <iostream>
#include <vector>
#include <math.h>
#define ull long long int

using namespace std;

ull Min, Max;


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> Min >> Max;

	vector<bool> sieve(Max - Min + 1, false);

	long long int i = 2;

	while (i * i <= Max) {
		long long int sNum = Min / (i * i);
		if (Min % (i * i) != 0) sNum++;

		while (sNum * (i * i) <= Max) {
			if (!sieve[sNum * (i * i) - Min])
				sieve[sNum * (i * i) - Min] = true;
			sNum += 1;
		}
		i++;
	}

	int ans = 0;
	for (int i = 0; i < sieve.size(); i++) if (!sieve[i]) ans++;
	cout << ans;

	return 0;
}