#include <bits/stdc++.h>
#define INF 987654321

using namespace std;
using ll = long long;

ll N, M;

ll S, E;

vector<pair<ll, ll>> ve[1001];

vector<ll> ans[1001];

vector<ll> dijkstra(ll start) {
	vector<ll> d(N + 1, INF);
	d[start] = 0;
	priority_queue<pair<ll, ll >> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		ll cost = -pq.top().first;
		ll from = pq.top().second;
		pq.pop();

		if (d[from] < cost) continue;

		for (ll i = 0; i < ve[from].size(); i++) {
			ll next = ve[from][i].first;
			ll nextDistance = cost + ve[from][i].second;
			if (nextDistance <= d[next]) {
				if (nextDistance == d[next]) {
					ans[next].pop_back();
				}
				ans[next].push_back(from);
				d[next] = nextDistance;
				pq.push(make_pair(-nextDistance, next));
			}
		}
	}
	return d;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	cin >> M;
	for (ll i = 0; i < M; i++) {
		ll A, B, dist;
		cin >> A >> B >> dist;
		ve[A].push_back({ B, dist });
	}
	cin >> S >> E;
	vector<ll> d = dijkstra(S);

	cout << d[E] << '\n';
	cout << ans[E].size() + 1 << '\n';
	for (ll i = 0; i < ans[E].size(); i++) {
		cout << ans[E][i] << ' ';
	}
	cout << E;

	return 0;
}