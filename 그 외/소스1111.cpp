#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int arr[11][11];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    vector <int> k(n);
    for (int i = 0; i < n; i++) {
        k[i] = i;
    }

    int mi = 987654321;

    do {
        bool find_zero = true;
        int sum = 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i][k[i]] == 0 || arr[n - 1][k[n - 1]] == 0) {
                find_zero = false;
                break;
            }
            else sum = sum + arr[i][k[i]];
        }

        if (find_zero == true) {
            sum = sum + arr[n - 1][k[n - 1]];
            if (mi > sum) {
                mi = sum;
            }
        }

    } while (next_permutation(k.begin(), k.end()));
    cout << mi << '\n';




    return 0;
}