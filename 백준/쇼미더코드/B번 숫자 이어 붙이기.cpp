#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#define MOD 1000000007

using namespace std;

int N, Q;
int A[1001];

vector<int> road[1001];
bool check[1001];


void func(int start, int target, vector<int>& ans) {
	if (start == target) {
		string ret = "";
		for (int i = 0; i < ans.size(); i++) {
			ret += to_string(ans[i]);
			if (stoull(ret) > MOD) ret = to_string(stoull(ret) % MOD);
		}
		cout << ret << '\n';
		return;
	}

	for (int i = 0; i < road[start].size(); i++) {
		if (!check[road[start][i]]) {
			check[road[start][i]] = true;
			ans.push_back(A[road[start][i]]);
			func(road[start][i], target, ans);
			check[road[start][i]] = false;  ans.pop_back();
		}
	}
	return;
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N - 1; i++) {
		int a, b; cin >> a >> b;
		road[a].push_back(b);
		road[b].push_back(a);
	}

	for (int i = 0; i < Q; i++) {
		int a, b; cin >> a >> b;
		check[a] = true;
		vector<int> ve;
		ve.push_back(A[a]);
		func(a, b, ve);
		memset(check, 0, sizeof(check));
	}

	return 0;
}