#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;

int N, M;

vector<int> Resource(51, 0); // 수정 필요

int Max[51][51];
int Allocate[51][51];
int Need[51][51];

string qus;
queue<pair<int, vector<int> > > Wait;

bool canRequest(int P, vector<int>& Request) {
	bool flag = false; // false: 실행 X true : 실행 O
	for (int i = 0; i < M; i++) if (Need[P][i] < Request[i]) return true;

	for (int i = 0; i < M; i++) {
		Resource[i] -= Request[i];
		Allocate[P][i] += Request[i];
		Need[P][i] -= Request[i];
	}

	for (int i = 0;i < N; i++) {
		bool can = false;
		for (int j = 0; j < M; j++) {
			if (Resource[j] < 0 || Need[i][j] > Resource[j]) can = true; // can = true 돌면 안됨
		}
		if (!can) flag = true;
	}

	if (!flag) {
		for (int i = 0; i < M; i++) {
			Resource[i] += Request[i];
			Allocate[P][i] -= Request[i];
			Need[P][i] += Request[i];
		}
		return false;
	}
	else if(flag) { // 실행해도 괜찮음

		return true;
	}
}

int main(void) {
	freopen("banker.inp", "r", stdin);
	freopen("banker.out", "w", stdout);

	cin >> N >> M;

	for (int i = 0; i < M; i++) cin >> Resource[i];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> Max[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Allocate[i][j];
			Resource[j] -= Allocate[i][j];
			Need[i][j] = Max[i][j] - Allocate[i][j];
		}
	}

	while (1) {
		cin >> qus;
		if (qus == "quit") break;

		if (qus == "request") {
			int P; vector<int> Request(M + 1);
			cin >> P;
			for (int i = 0; i < M; i++) cin >> Request[i];
			if (!canRequest(P, Request)) Wait.push(make_pair(P, Request));
		}
		else if (qus == "release") {
			int P; vector<int> Release(M + 1);
			cin >> P;
			for (int i = 0; i < M; i++) cin >> Release[i];
			for (int i = 0; i < M; i++) {
				Resource[i] += Release[i];
				Allocate[P][i] -= Release[i];
				Need[P][i] += Release[i];
			}
			queue<pair<int, vector<int> > > temp;
			while (!Wait.empty()) {
				int WaitP = Wait.front().first;
				vector<int> Request = Wait.front().second;
				Wait.pop();

				if (!canRequest(WaitP, Request)) temp.push(make_pair(WaitP, Request));
			}
			Wait = temp;
			while (!temp.empty()) temp.pop();
		}

		for (int i = 0; i < M; i++) cout << Resource[i] << ' ';
		cout << '\n';
	}

	return 0;
}