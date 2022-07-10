#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>
#include<string>
#include <iostream>
#define MAX 10000

using namespace std;

int main() {
    int N,
        i, k,
        b,
        cnt, dp[MAX];
    string v;

    while (scanf("%d ", &N) != EOF) {
        int i = 0;
        cnt = 0;
        while (N--) {
            getline(cin, v);

            for (k = 0; k < v.size(); k++) {
                b = 1;
                b  <<= (v[k] - '1');
            }

            if (dp[b] != i) {
                cnt++;
                dp[b] = i;
            }
        }
        printf("%d\n", cnt);
        i++;
    }

    return 0;
}