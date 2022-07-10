//
//  Copyright (c) 2021 HyeJin Shin All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable : 4996)
#define uul long long int

using namespace std;
uul func(uul a, uul b) {
    uul n = 1;
    while (1) {
        if (a == 1) { break; }
        else if (a > b) { n--; break; }

        if (a % 2 == 0) {
            a = a / 2;
        }
        else {
            a = 3 * a + 1;
        }
        n++;

    }
    return n;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("sequence.inp", "r", stdin);
    freopen("sequence.out", "w", stdout);
    uul a, b;
    uul k = 1;
    while (1) {
        cin >> a >> b;
        if (a == -1 && b == -1)break;
        cout << "Case " << k << ": A = " << a << ", limit = " << b << ", number of terms = " << func(a, b) << '\n';
        k++;
    }
}
