#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321;

using namespace std;


int d[20001][20001];
bool check[20001];

void floyedwarshall(int n) {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
			}
		}
	}
}

int func(vector<int>& ve,int n) {
	int ans = 0;
	if (ve.size() == 3) {
		if (d[ve[0]][ve[1]] + d[ve[1]][ve[2]] == d[ve[0]][ve[2]]) return 1;
		else return 0;
	}

	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			check[i] = true; ve.push_back(i);
			ans += func(ve, n);
			check[i] = false; ve.pop_back();
		}
	}
	return ans;
}

long long solution(int n, vector<vector<int>> edges) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) d[i][j] = 0;
			else d[i][j] = INF;
		}
	}

	for (int i = 0; i < edges.size(); i++) {
		for (int j = 0; j < edges[i].size(); j++) {
			d[i][edges[i][j]] = 1;
			d[edges[i][j]][i] = 1;
		}
	}

	floyedwarshall(n);
	long long answer = 0;
	
	vector<int> ve;
	answer = func(ve, n);

	return answer;
}

int main(void) {
	int n = 4;
	vector<vector<int>> edges(n);

	edges[2].push_back(3);
	edges[0].push_back(1);
	edges[1].push_back(2);

	cout << solution(n, edges);

	return 0;
}