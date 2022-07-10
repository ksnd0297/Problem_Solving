#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int arr[101][101];
bool check[101][101];

int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

int N;

void Dfs(int y, int x) {
    check[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int tempY = y + dir[i][0];
        int tempX = x + dir[i][1];
        if (tempY >= 0 && tempY < N && tempX >= 0 && tempX < N) {
            if (!check[tempY][tempX]) {
                Dfs(tempY, tempX);
            }
        }
    }
}

int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    for (int k = 0; k <= 100; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j] <= k) check[i][j] = true;
            }
        }

        int Count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!check[i][j]) {
                    Dfs(i, j);
                    Count++;
                }
            }
        }
        ans = max(ans, Count);
        memset(check, 0, sizeof(check));
    }
    cout << ans;
    return 0;
}