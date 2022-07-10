#pragma warning(disable:4996)
#include <stdio.h>
#include <queue>
using namespace std;

int arr[22][22];

struct Cood {
    int x, y, time;

    bool operator<(const Cood c) const {
        if (this->time == c.time) {
            if (this->y == c.y) {
                return this->x > c.x;
            }
            return this->y > c.y;
        }
        return this->time > c.time;
    }
};

struct Shark {
    int x, y, size, fish, time;
    int visit[22][22];
    int visit_cnt;
    priority_queue<Cood> q;

    Shark() {
        size = 2;
        fish = 0;
        time = 0;
        visit_cnt = 1;
    }

    void clear() {
        while (!q.empty()) q.pop();
        visit_cnt++;
    }
    bool eat(Cood cood) {
        int food_size = arr[cood.y][cood.x];
        if (size <= food_size || food_size == 0) return false;

        arr[cood.y][cood.x] = 0;
        fish++;
        if (!(fish %= size)) { // ¼ºÀå
            size++;
        }
        return true;
    }

    bool isMove(Cood cood) {
        int food_size = arr[cood.y][cood.x];
        return size >= food_size && visit[cood.y][cood.x] != visit_cnt;
    }

    void pushQ(Cood cood) {
        visit[cood.y][cood.x] = visit_cnt;
        q.push(cood);
    }

    Cood popQ() {
        Cood r = q.top();
        q.pop();
        return r;
    }

    void move(Cood cood) {
        x = cood.x;
        y = cood.y;
        time += cood.time;
    }

    bool pathFinding() {
        pushQ({ x, y, 0 });

        while (!q.empty()) {
            Cood cood = popQ();

            if (eat(cood)) {
                move(cood);
                clear();
                return true;
            }

            int timeTmp = cood.time + 1;
            Cood up = { cood.x, cood.y - 1, timeTmp };
            Cood left = { cood.x - 1, cood.y, timeTmp };
            Cood right = { cood.x + 1, cood.y, timeTmp };
            Cood down = { cood.x, cood.y + 1, timeTmp };

            if (isMove(up)) {
                pushQ(up);
            }

            if (isMove(left)) {
                pushQ(left);
            }

            if (isMove(right)) {
                pushQ(right);
            }

            if (isMove(down)) {
                pushQ(down);
            }
        }

        return false;
    }
};

int main() {
    int N;
    Shark baby;

    scanf("%d", &N);

    for (int i = 0; i <= N + 1; i++) {
        arr[0][i] = 100000;
        arr[N + 1][i] = 100000;

        arr[i][0] = 100000;
        arr[i][N + 1] = 100000;
    }

    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            scanf("%d%", &arr[y][x]);

            if (arr[y][x] == 9) {
                baby.move({ x, y, 0 });
                arr[y][x] = 0;
            }
        }
    }

    while (baby.pathFinding()) {}

    printf("%d", baby.time);
    return 0;
}