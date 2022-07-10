#include <iostream>
#include <vector>
#pragma warning(disable :4996)

using namespace std;

vector<int> P[1001]; //각 프로세스들이 돌아가는 시간들

int ans;
int IoTime[1001]; // -1이되면 프로그램 종료

vector<int>IdleTime;

int N;

bool check() {
	for (int i = 0; i < N; i++) {
		if (IoTime[i] != -1) return false;
	}
	return true; // 모든 IoTime 이 -1 즉 끝나면 종료
}

int again() { // 다시 돌아갈게 있는지 본다
	int ret = INT32_MAX;
	for (int i = 0; i < N; i++) {
		if (IoTime[i] != -1) {
			if (ans >= IoTime[i]) return -1; //돌아갈게 있다
			else if (ans < IoTime[i]) ret = min(ret, IoTime[i] - ans); // 돌아갈게 없다 IdleTime, CPU가동시간 추가
		}
	}
	return ret;
}

int main(void) {
	freopen("multi.inp", "r", stdin);
	freopen("multi.out", "w", stdout);

	cin >> N;
	for (int i = 0; i < N; i++) {
		while (1) {
			int num; cin >> num;
			P[i].push_back(num);
			if (num == -1) break;
		}
	}

	int a = 0;

	while (1) {
		if (check()) {
			break;
		}
		bool flag = false;
		for (int i = 0; !flag && i < N; i++) {
			if (IoTime[i] != -1 && ans >= IoTime[i]) {
				for (int j = 0; j < P[i].size(); j++) {
					if (P[i][j] == -1) { P[i][j] = 0; IoTime[i] = -1; } // 끝까지 돌았을 경우
					if (P[i][j] != 0 && j % 2 == 0) { // CPU 타임 짝수
						ans += P[i][j]; P[i][j] = 0;
					}
					else if (P[i][j] != 0 && j % 2 != 0) { // IO 타임 홀수
						IoTime[i] = ans + P[i][j]; 
						if (P[i][j + 1] == -1) {
							int cnt = 0;
							for (int i = 0; i < N; i++) {
								if (P[i][P[i].size() - 1] == 0) {
									cnt++; 
								}
							}
							if (cnt == N - 1) {
								ans += P[i][j];
								flag = true;
							}
						}
						P[i][j] = 0;
						break;
					}
				}
				if (again() == -1) flag = true; // 돌아갈게 있다 return -1
			}
		}
		if (!flag) {
			int idle = again();
			if (idle == INT32_MAX)break;
			if (idle != 0)
				IdleTime.push_back(idle);
			ans += idle;
		}
	}


	for (int i = 0; i < IdleTime.size(); i++) a += IdleTime[i];
	cout << a << ' ' << ans << '\n';

	return 0;
}