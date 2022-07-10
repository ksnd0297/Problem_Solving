#include <iostream>

using namespace std;

double she[4][11]; // [A][] [B][] [C][] [D][]

double perc[4][4];

int main(void)
{
	she[0][0] = 0.25; she[1][0] = 0.25; she[2][0] = 0.25; she[3][0] = 0.25;
	
	int N; cin >> N;
	int M; cin >> M;
	for (int i = 0; i < M; i++) {
		char A, B; double C; cin >> A >> B >> C;
		perc[A - 'A'][B - 'A'] = C;
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				if (perc[j][k] != 0) {
					she[k][i] += she[j][i - 1] * perc[j][k];
				}
			}
		}
	}
	
	cout << fixed;
	cout.precision(2);
	for (int i = 0; i < 4; i++) cout << she[i][N] * 100 << '\n';
	return 0;
}