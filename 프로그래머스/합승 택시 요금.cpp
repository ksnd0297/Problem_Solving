#include <string>
#include <vector>

using namespace std;

int map[201][201];

void floydWarshall(int n) {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][k] + map[k][j] < map[i][j]) map[i][j] = map[i][k] + map[k][j];
			}
		}
	}
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(i != j)map[i][j] = 123456789;
		}
	}

	for (int i = 0; i < fares.size(); i++) {
		map[fares[i][0]-1][fares[i][1]-1] = fares[i][2];
		map[fares[i][1]-1][fares[i][0]-1] = fares[i][2];
	}

	floydWarshall(n);
	int min = 123456789;
	for (int i = 0; i < n; i++) {
		if (min > map[s - 1][i] + map[i][a - 1] + map[i][b - 1]) min = map[s - 1][i] + map[i][a - 1] + map[i][b - 1];
	}
	int answer = min;
	return answer;
}