#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <cstring>
#pragma warning(disable : 4996)

using namespace std;

int T, n, k, X, Y, a, b;

struct soccerTeam {
    int teamNum;
    int win;
    int homeGoal;
    int homeGoaled;
    int awayGoal;
    int awayGoaled;
};

soccerTeam teamArr[41];

bool compare(soccerTeam A, soccerTeam B) {
    if (A.win > B.win) return true;
    else if (A.win == B.win) {
        int AgoalScore = A.awayGoal + A.homeGoal - A.awayGoaled - A.homeGoaled;
        int BgoalScore = B.awayGoal + B.homeGoal - B.awayGoaled - B.homeGoaled;
        if (AgoalScore > BgoalScore) return true;
        else if (AgoalScore == BgoalScore) {
            if (A.awayGoal > B.awayGoal) return true;
            else return false;
        }
        else return false;
    }
    else return false;
}

int main(void) {
    freopen("soccer.inp", "r", stdin);
    freopen("soccer.out", "w", stdout);

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < 41; j++)
        {
            teamArr[j].teamNum = j + 1;
        }
        cin >> n >> k;
        for (int j = 0; j < n * k * (n - 1); j++)
        {
            cin >> X >> Y >> a >> b;
            Y = abs(Y);

            X -= 1; Y -= 1;

            teamArr[X].awayGoal += a;
            teamArr[X].awayGoaled += b;
            teamArr[Y].homeGoal += b;
            teamArr[Y].homeGoaled += a;
            if (a > b) teamArr[X].win += 3;
            else if (a == b) {
                teamArr[X].win += 1;
                teamArr[Y].win += 1;
            }
            else teamArr[Y].win += 3;
        }

        sort(teamArr, teamArr + n, compare);
        int rank = 0;
        int rankArr[41];
        int realArr[41];
        for (int j = 0; j < n; j++)
        {
            rankArr[teamArr[j].teamNum - 1] = j + 1;
        }
        for (int j = 1; j < n; j++)
        {
            /*if (teamArr[rankArr[j] - 1].win == teamArr[rankArr[j - 1] - 1].win) {
                int AgoalScore = teamArr[rankArr[j] - 1].awayGoal + teamArr[rankArr[j] - 1].homeGoal - teamArr[rankArr[j] - 1].awayGoaled - teamArr[rankArr[j] - 1].homeGoaled;
                int BgoalScore = teamArr[rankArr[j - 1] - 1].awayGoal + teamArr[rankArr[j - 1] - 1].homeGoal - teamArr[rankArr[j - 1] - 1].awayGoaled - teamArr[rankArr[j - 1] - 1].homeGoaled;
                if (AgoalScore == BgoalScore) {
                    if (teamArr[rankArr[j] - 1].awayGoal == teamArr[rankArr[j - 1] - 1].awayGoal) {
                        rankArr[j] = rankArr[j - 1];
                    }
                }
            }*/
            if (teamArr[j].win == teamArr[j - 1].win) {
                int AgoalScore = teamArr[j].awayGoal + teamArr[j].homeGoal - teamArr[j].awayGoaled - teamArr[j].homeGoaled;
                int BgoalScore = teamArr[j - 1].awayGoal + teamArr[j - 1].homeGoal - teamArr[j - 1].awayGoaled - teamArr[j - 1].homeGoaled;
                if (AgoalScore == BgoalScore) {
                    if (teamArr[j].awayGoal == teamArr[j - 1].awayGoal) {
                        rankArr[teamArr[j].teamNum - 1] = rankArr[teamArr[j - 1].teamNum - 1];
                    }
                }
            }
        }

        cout << "Test Case #" << i + 1 << ": ";
        for (int j = 0; j < n; j++)
        {
            cout << rankArr[j] << ' ';
        }
        cout << '\n';
        memset(teamArr, 0, sizeof(teamArr));
    }

    return 0;
}