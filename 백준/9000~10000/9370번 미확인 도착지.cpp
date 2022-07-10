#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

#define INF 123456789

using namespace std;

int T; // 테스트 케이스
int n, m, t; // 교차로, 도로, 목적지 후보의 개수
int s, g, h; // 예술가들의 출발지, 냄새를 맡은 도로
int a, b, d;  // a와 b 사이에 길이 d의 양방향 도로
int x; // 목적지 후보

int map[2006][2006];

bool visit[3][2006];
int dist[3][2006];

int getSmallIndex(int p) {
	int min = INF;
	int index = 1;
	for (int i = 1; i <= n; i++) {
		if (dist[p][i] < min && !visit[p][i]) {
			min = dist[p][i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start, int p) {
	for (int i = 1; i <= n; i++) dist[p][i] = map[start][i];
	visit[p][start] = true;
	for (int i = 1; i <= n; i++) {
		int current = getSmallIndex(p);
		visit[p][current] = true;
		for (int j = 1; j <= n; j++) {
			if (!visit[p][j]) {
				if (dist[p][current] + map[current][j] < dist[p][j]) dist[p][j] = dist[p][current] + map[current][j];
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--) {
		vector<int> target; // 목적지 저장 vector
		cin >> n >> m >> t;
		cin >> s >> g >> h;

		for (int i = 1; i <= n; i++) { // 기존 맵 초기화
			for (int j = 1; j <= n; j++) {
				if(i != j) map[i][j] = INF;
			}
		}
		memset(dist, 0, sizeof(dist));
		memset(visit, 0, sizeof(visit));

		for (int i = 0; i < m; i++) {
			cin >> a >> b >> d;
			if (map[a][b] == 0) map[a][b] = map[b][a] = d;
			if (map[a][b] != 0 && map[a][b] > d)map[a][b] = map[b][a] = d;

		}
		for (int i = 0; i < t; i++) { cin >> x; target.push_back(x); }

		dijkstra(s, 0); // start
		dijkstra(g, 1); // g
		dijkstra(h, 2); // h

		sort(target.begin(), target.end());
		// s 출발지 g h 냄새를 맡은 도로 target 목적지
		for (int i = 0; i < target.size(); i++) {
			if (g != s && h != s) {
				if (dist[0][target[i]] == dist[0][g] + dist[1][h] + dist[2][target[i]] || dist[0][target[i]] == dist[0][h] + dist[2][g] + dist[1][target[i]]) cout << target[i] << ' ';
			}
			else if (g == s) {
				if (dist[0][target[i]] == dist[0][h] + dist[2][target[i]]) cout << target[i] << ' ';
			}
			else if (h == s) {
				if (dist[0][target[i]] == dist[0][g] + dist[1][target[i]]) cout << target[i] << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}