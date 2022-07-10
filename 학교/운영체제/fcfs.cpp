#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>
#pragma warning(disable :4996)

using namespace std;

struct compare {
	bool operator()(pair<int, tuple<int, int, int>>a, pair<int, tuple<int, int, int>>b) {
		if (a.first == b.first) return get<2>(a.second) > get<2>(b.second);
		return a.first > b.first;
	}
};

priority_queue<pair<int, tuple<int, int, int>>, vector<pair<int, tuple<int, int, int>>>, compare> pq;
int N;

queue<int> P[1001];

int endTime[1001];

int cpuTime;
int idleTime;

void Init() {
	for (int i = 0; i < N; i++) {
		int time = P[i].front(); P[i].pop();
		int cpuTime = P[i].front(); P[i].pop();
		int ioTime = P[i].front(); P[i].pop();
		pq.push({ time,{cpuTime, ioTime, i } });
	}
}

bool end() {
	for (int i = 0; i < N; i++) {
		if (P[i].size() != 0) return false;
	}
	return true;
}

int main(void) {
	freopen("fcfs.inp", "r", stdin);
	freopen("fcfs.out", "w", stdout);

	cin >> N;
	for (int i = 0; i < N; i++) {
		while (1) {
			int num; cin >> num;
			if (num == -1) break;
			P[i].push(num);
		}
	}

	Init();

	while (!pq.empty()) {
		int nowTime, cpu, io, index;
		nowTime = pq.top().first;
		tie(cpu, io, index) = pq.top().second;  pq.pop();

		if (cpuTime >= nowTime) cpuTime += cpu;
		else {
			int gap = nowTime - cpuTime;
			cpuTime += gap + cpu;
			idleTime += gap;
		}

		if (P[index].empty()) {
			endTime[index] = cpuTime + io;
		}

		int nextCpuTime = 0;
		int nextIoTime = 0;

		if (P[index].size() == 1) {
			nextCpuTime = P[index].front(); P[index].pop();
			pq.push({ cpuTime + io, {nextCpuTime, nextIoTime, index} });
		}
		else if (P[index].size() >= 2) {
			nextCpuTime = P[index].front(); P[index].pop();
			nextIoTime = P[index].front(); P[index].pop();
			pq.push({ cpuTime + io, {nextCpuTime, nextIoTime, index} });
		}
	}

	cout << idleTime << '\n';
	for (int i = 0; i < N; i++) {
		cout << endTime[i] << '\n';
	}

	return 0;
}