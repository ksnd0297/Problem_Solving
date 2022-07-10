#include <bits/stdc++.h>
#define INF 987654321;

using namespace std;

int N, M;
int Six = INF;
int One = INF;

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B; cin >> A >> B;
		Six = min(Six, A);
		One = min(One, B);
	}

	if (Six > One * 6) cout << One * N;
	else cout << (N / 6) * Six + (N % 6 * One > Six ? Six : N % 6 * One);

	return 0;
}