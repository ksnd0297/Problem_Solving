#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int check[100002];
int inpArr[100002];
int ans;
int cntRoad;
int N, K;

void bfs(int N, int K) {
	queue <tuple<int, int>> q;
	q.push(make_tuple(N, 0));
	check[N] = 1;
	if (N == K) return;// todo
	while (!q.empty()) {
		int x, cnt;
		tie(x, cnt) = q.front();
		q.pop();
		if (ans != 0 && cnt > ans) continue;

		if (x - 1 >= 0) { //-1 이동일 때 범위 안에 존재 할 때
			if (check[x - 1] == 0) { // 가고자 하는 곳이 방문하지 않은 곳일 때
				if (x - 1 == K)
				{
					inpArr[x - 1] = inpArr[x] + 1;
					check[x - 1] = 1;
					if (!ans) {
						ans = cnt + 1;
						cntRoad++;
					}
				}
				else {
					check[x - 1] = 1;
					inpArr[x - 1] = inpArr[x] + 1;
					q.push(make_tuple(x - 1, cnt + 1));
				}
			}
			else {
				if (inpArr[x - 1] == inpArr[x] + 1) {
					if (x - 1 == K)
					{
						if (ans == cnt + 1) {
							cntRoad++;
						}
					}
					q.push(make_tuple(x - 1, cnt + 1));
				}
			}
		}
		if (x + 1 <= 100000) { //+1 이동일 때 범위 안에 존재 할 때
			if (check[x + 1] == 0) { // 가고자 하는 곳이 방문하지 않은 곳일 때
				if (x + 1 == K)
				{
					inpArr[x + 1] = inpArr[x] + 1;
					check[x + 1] = 1;
					if (!ans) {
						ans = cnt + 1;
						cntRoad++;
					}
				}
				else {
					check[x + 1] = 1;
					inpArr[x + 1] = inpArr[x] + 1;
					q.push(make_tuple(x + 1, cnt + 1));
				}
			}
			else {
				if (inpArr[x + 1] == inpArr[x] + 1) {
					if (x + 1 == K)
					{
						if (ans == cnt + 1) {
							cntRoad++;
						}
					}
					q.push(make_tuple(x + 1, cnt + 1));
				}
			}
		}
		if (x * 2 <= 100000) { //*2 이동일 때 범위 안에 존재 할 때
			if (check[x * 2] == 0) { // 가고자 하는 곳이 방문하지 않은 곳일 때
				if (x * 2 == K)
				{
					inpArr[x * 2] = inpArr[x] + 1;
					check[x * 2] = 1;
					if (!ans) {
						ans = cnt + 1;
						cntRoad++;
					}
				}
				else {
					check[x * 2] = 1;
					inpArr[x * 2] = inpArr[x] + 1;
					q.push(make_tuple(x * 2, cnt + 1));
				}
			}
			else {
				if (inpArr[x * 2] == inpArr[x] + 1) {
					if (x * 2 == K)
					{
						if (ans == cnt + 1) {
							cntRoad++;
						}
					}
					q.push(make_tuple(x * 2, cnt + 1));
				}
			}
		}
	}
}

int main() {
	cin >> N >> K;
	inpArr[N] = 0;

	bfs(N, K);
	if (N == K) {
		cout << 0 << '\n' << 1;
	}
	else {
		cout << ans << '\n' << cntRoad;
	}


	return 0;
}