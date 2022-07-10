#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[10], sum = 0;
    for (int i = 0; i < 9; i++) {
        cin >> arr[i]; // 배열 안에 값 넣기
        sum += arr[i]; // 합 구하기
    }
    sort(arr, arr + 9);

    bool flag = false;
    for (int i = 0;!flag &&  i < 8; i++) {
        for (int j = i + 1;!flag &&  j < 9; j++) {
            if (sum - (arr[i] + arr[j]) == 100) {
                for (int a = 0; a < 9; a++) {
                    if (a == i || a == j) continue;
                    cout << arr[a] << '\n';
                    flag = true;
                }
            }
        }
    }


    return 0;
}