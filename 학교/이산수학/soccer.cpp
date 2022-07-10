#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#pragma warning(disable : 4996)

using namespace std;

int T;
int N, K;

int rank[1001];

struct Team {
	int awayIn = 0; // away¿¡¼­ ³ÖÀº °ñ
	int awayOut = 0; // away¿¡¼­ ÀÒÀº °ñ
	int homeIn = 0; // home¿¡¼­ ³ÖÀº °ñ
	int homeOut = 0; // home¿¡¼­ ÀÒÀº °ñ
	int win = 0; // ½ÂÁ¡
};

Team team[41];


int main(void) {

	freopen("soccer.inp", "r", stdin);
	freopen("soccer.out", "w", stdout);

	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cin >> N >> K;
		for (int i = 0; i < (2 * K * (N - 1)) * (N / 2); i++) {
			int awayTeam, homeTeam, awayGoal, homeGoal;
			scanf("%d-%d %d %d", &awayTeam, &homeTeam, &awayGoal, &homeGoal);
			if (awayGoal > homeGoal)team[awayTeam].win += 3;
			else if (awayGoal < homeGoal) team[homeTeam].win += 3;
			else {
				team[awayTeam].win += 1;
				team[homeTeam].win += 1;
			}
			team[awayTeam].awayIn += awayGoal;
			team[awayTeam].awayOut += homeGoal;
			team[homeTeam].homeIn += homeGoal;
			team[homeTeam].homeOut += awayGoal;
		}

		for (int a = 1; a <= N; a++) {
			int rank = 1;
			for (int b = 1; b <= N; b++) {
				if (a == b) continue;
				if (team[a].win < team[b].win) rank++;
				else if (team[a].win == team[b].win) {
					int aTeamGoal = (team[a].awayIn + team[a].homeIn) - (team[a].awayOut + team[a].homeOut);
					int bTeamGoal = (team[b].awayIn + team[b].homeIn) - (team[b].awayOut + team[b].homeOut);
					if (aTeamGoal < bTeamGoal) rank++;
					else if (aTeamGoal == bTeamGoal) {
						if (team[a].awayIn < team[b].awayIn) rank++;
					}
				}
			}
			::rank[a] = rank;
		}

		cout << "Test Case #" << i << ": ";
		for (int i = 1; i <= N; i++) cout << ::rank[i] << ' ';
		cout << '\n';

		memset(::rank, 0, sizeof(::rank));
		memset(team, 0, sizeof(team));
	}
	return 0;
}