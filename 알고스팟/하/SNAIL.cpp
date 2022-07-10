#include <iostream>

using namespace std;

int N, M;
double cache[1000][2000];

double climb(int days, int climbs) {
	double& ret = cache[days][climbs];
	if (days == M) return ret = climbs >= N ? 1 : 0;
	if (ret != -1) return ret;
	return  ret =  (0.25*climb(days + 1, climbs + 1)) + (0.75*climb(days + 1, climbs + 2));
}

int main() {
	int C; cin >> C;
	while (C--) {
		for (int i = 0; i < 1000; i++)
			for (int j = 0; j < 2000; j++)
				cache[i][j] = -1;

		cin >> N >> M;
		cout.precision(11);
		cout << climb(0, 0) << '\n';
		

	}
	return 0;
}