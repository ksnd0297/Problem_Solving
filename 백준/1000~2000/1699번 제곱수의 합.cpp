#include <stdio.h>

bool arr[1000001]; // 전역 선언시 false 로 초기화 되어 있음

int main() {
    int N;
    // 지우는 걸 true, 안지워 지는 걸 false ==> 소수는 false
    arr[0] = true;
    arr[1] = true;
    int cnt = 0;
    for (int i = 2; i <= 1000001; i++)
    {
        for (int j = 2; j * i <= 1000001; j++)
        {
            arr[i * j] = true;
            cnt++;
        }
    }
    
    printf("%d", cnt);

    return 0;
}