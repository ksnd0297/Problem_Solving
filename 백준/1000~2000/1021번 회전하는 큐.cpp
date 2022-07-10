#include <iostream>
#include <queue>

using namespace std;

deque<int> dq;

int N, M;

int main(void) {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) dq.push_back(i);

	int ans = 0;
	for (int i = 0; i < M; i++) {
		int num; cin >> num;

		deque<int>front = dq; // ¾Õ¿¡¼­ »¬ Å¥
		deque<int> back = dq; // µÚ¿¡¼­ »¬ Å¥

		int frontCnt = 0;
		while (front.front() != num) {
			int frontNum = front.front();
			front.push_back(frontNum);
			front.pop_front();
			frontCnt++;
		}

		int backCnt = 0;
		while (back.front() != num) {
			int backNum = back.back();
			back.push_front(backNum);
			back.pop_back();
			backCnt++;
		}

		if (frontCnt >= backCnt) {
			ans += backCnt;
			back.pop_front();
			dq = back;
		}
		else {
			ans += frontCnt;
			front.pop_front();
			dq = front;
		}
	}
	cout << ans;
	return 0;
}