#include <iostream>
#pragma warning(disable : 4996)
using namespace std;

int N;
int cpuTime, idleTime;
int t, k;

int main(void) {
	freopen("batch.inp", "r", stdin);
	freopen("batch.out", "w", stdout);

	cin >> N;
	while (N--) {
		while (1) {
			cin >> t; // cpu 시간
			if (t == -1) break;
			cin >> k; // idle 시간
			if (k == -1) {cpuTime += t; break;}
			cpuTime += t; idleTime += k;
		}
	}
	cout << idleTime << ' ' << cpuTime + idleTime;
	return 0;
}