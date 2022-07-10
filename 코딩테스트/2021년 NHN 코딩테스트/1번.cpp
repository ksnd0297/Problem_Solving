#include <iostream>
#include <string>
#include <vector>
#pragma warning(disable : 4996)

using namespace std;

bool tree[100001];

struct query {
	string operation;
	int branchNum;
};

struct input_data {
	int n;
	query* queries;
};

vector<int> mergeNum;

void process_stdin(input_data& inputData) {
	cin >> inputData.n;

	inputData.queries = new query[inputData.n];

	for (int i = 0; i < inputData.n; i++) {
		cin >> inputData.queries[i].operation;

		if (inputData.queries[i].operation == "merge") {
			cin >> inputData.queries[i].branchNum;
		}
	}
}

void solution(int n, query* queries) {
	tree[1] = true; // 1¹ø °¡Áö TRUE
	int pos = 2;
	for (int i = 0; i < n; i++) {
		if (queries[i].operation[0] == 'b') { // branch
			int idx = pos;
			bool flag = false;
			for (int j = 0; j < mergeNum.size(); j++) {
				if (mergeNum[j] < idx && !tree[mergeNum[j]]) {
					idx = mergeNum[j]; flag = true;
				}
			}
			if (flag) { tree[idx] = true;}
			else { tree[pos] = true; pos++; }
		}
		else if (queries[i].operation[0] == 'm') { // merge
			mergeNum.push_back(queries[i].branchNum);
			tree[queries[i].branchNum] = false;
		}
	}

	for (int i = 1; i <= n + 1; i++) {
		if (tree[i]) cout << i << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input_data inputData;
	process_stdin(inputData);

	solution(inputData.n, inputData.queries);

	return 0;
}
