#include <iostream>
#include <vector>

using namespace std;

vector<int> vill[51]; // 마을의 갯수
double dis[100][50]; // [일수][마을] 확률을 넣음
int N, D, P; // N : 마을의 수 D : 지난일 수 P : 교도소 위치

double dunibal(int day) {
	if (day == D) return 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < vill[i].size(); j++) {
			dis[day + 1][vill[i][j]] += dis[day][i] / vill[i].size();
		}
	}
	dunibal(day + 1);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int C; cin >> C;
	while (C--) {
		cin >> N >> D >> P;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int num; cin >> num;
				if (num == 1) vill[i].push_back(j);
			}
		}
		dis[0][P] = 1;
		dunibal(0);

		int K; cin >> K;
		for (int i = 0; i < K; i++) {
			int num; cin >> num;
			cout.precision(8);
			cout << dis[D][num] << ' ';
		}
		cout << '\n';

		for (int i = 0; i <= D; i++) {
			for (int j = 0; j <= N; j++) {
				dis[i][j] = 0;
			}
		}
		for (int i = 0; i < N; i++) vill[i].clear();
	}
	return 0;
}