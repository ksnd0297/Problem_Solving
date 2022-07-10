#include <iostream>
#define MAX(x,y) (x>y) ? (x) : (y)

using namespace std;

int queue[100001];

int main() {
	int Test; cin >> Test;
	while (Test--) {
		int N, M; cin >> N >> M;

		int front = 0; //삽입 시 0 부터 가르킴
		int rear = -1; //삽입 시 0 부터 가르킴
		int max = 0;

		int num;
		for (int i = 0; i < N; i++) {
			cin >> queue[i]; rear++;
			max = MAX(max, queue[i]); //초기 MAX값 갱신
		} // queue에 데이터 삽입 & rear ++

		int temp = M; //M의 인덱스
		int count = 0; // 몇 번째 횟수인가를 확인

		while (1) {
			if (max == queue[temp] && temp == front) break; // 가장 큰 값이 본인이고, M값의 위치가 front에 있을 경우

			if (front == temp && queue[front] != max) {
				queue[++rear] = queue[front++]; temp = rear;
			} // 가장 큰 수가 아니고 M의 위치일 경우 갱신
			else if (queue[front] != max) {
				queue[++rear] = queue[front++];
			} // 가장 큰 수가 아닐경우 뒤로 보냄
			else if (queue[front] == max) {
				front++; max = 0; count++;
				for (int i = front; i <= rear; i++) { max = MAX(max, queue[i]);}  // max의 값 갱신
			} // 그냥 제거
		}
		cout << count + 1 << endl;
	}
}