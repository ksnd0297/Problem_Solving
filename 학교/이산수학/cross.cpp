#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

using namespace std;

int T;
int N;

int S1[10001];

int pos[10001];
int line[10001];

int main(void)
{
	freopen("cross.inp", "r", stdin);
	freopen("cross.out", "w", stdout);

	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		memset(line, 0, sizeof(line));

		for (int i = 0; i < N; i++) cin >> S1[i];
		for (int i = 0; i < N; i++) {
			int Num; cin >> Num;
			pos[Num] = i;
		}

		int ans = 0;
		for (int i = 0; i < N; i++) {
			ans += line[pos[S1[i]]];
			for (int j = 0; j <= pos[S1[i]]; j++) line[j]++;
		}

		cout << "Case " << i << ": " << ans << '\n';
	}

	return 0;
}