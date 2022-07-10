#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;

int N, Q;
int Limit[101]; // 레벨 별 메모리 제한 0레벨부터 시작

struct Data {
	int key;
	int memory;
};

vector<Data> level[101];

void avalanche(int L) {
	int memorySum = 0;
	for (int i = 0; i < (int)level[L].size(); i++) {
		memorySum += level[L][i].memory;
	}

	if (memorySum <= Limit[L]) return;

	// 아래층으로 내리기
	for (int i = 0; i < (int)level[L].size(); i++) {
		bool flag = false;
		for (int j = 0; !flag && j < (int)level[L + 1].size(); j++) {
			if (level[L + 1][j].key == level[L][i].key) { //같은 키가 있을 경우
				level[L + 1][j].memory = level[L][i].memory; // 메모리 재할당
				flag = true;
			}
		}
		if (!flag) level[L + 1].push_back(level[L][i]);
	}
	level[L].clear();

	avalanche(L + 1);
}

void Insert(int key, int value) { // 키 & 차지하는 메모리 공간
	Data data;
	data.key = key;
	data.memory = value;
	level[0].push_back(data); // 값 삽입
	avalanche(0); // 0부터 재귀로 산사태 시작
}

void Find(int key) {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < (int)level[i].size(); j++) {
			if (level[i][j].key == key) {
				cout << i + 1 << ' ' << level[i][j].memory << '\n';
				return;
			}
		}
	}
	cout << "none" << '\n';
	return;
}



int main(void) {
	cin >> N >> Q;
	for (int i = 0; i < N - 1; i++) {
		cin >> Limit[i];
	}
	Limit[N - 1] = INF;

	for (int i = 0; i < Q; i++) {
		char ope;
		int key, value;
		cin >> ope;
		if (ope == 'I') { // Insert
			cin >> key >> value;
			Insert(key, value);
		}
		else if (ope == 'F') { // Find
			cin >> key;
			Find(key);
		}
	}

	return 0;
}