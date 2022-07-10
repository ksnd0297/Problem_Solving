#include <iostream>
#include <vector>

using namespace std;

int root = 0;
vector<int> pre;
vector<int> in;

void postorder(int start, int end)
{
	int i;
	for (i = start; i < end; i++) {
		if (pre[root] == in[i]) {
			root++;
			break;
		}
	}
	if (start < end) { //PostOrder
		postorder(start, i);
		postorder(i + 1, end);
		cout << in[i] << ' ';
	}
}

int main() {
	int C; cin >> C;
	while (C--) {
		int N; cin >> N;
		for (int i = 0; i < N; i++) {
			int num; cin >> num;
			pre.push_back(num);
		}
		for (int i = 0; i < N; i++) {
			int num; cin >> num;
			in.push_back(num);
		}
		postorder(0, N);
		cout << '\n';
		pre.clear(); in.clear();
		root = 0;
	}
	return 0;
}