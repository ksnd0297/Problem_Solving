#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define ull unsigned long long int 

using namespace std;

bool sieve(ull N) {
    if (N == 1 || N == 0) return false;
    for (ull i = 2; i <= (ull)sqrt(N); i++) {
        if (N % i == 0) return false;
    }
    return true;
}

ull findSieve(string str) {
    int ans = 0;
    string temp = "";
    for (ull i = 0; i < str.size();i++) {
        if (str[i] != '0') temp += str[i];
        else if (str[i] == '0' && temp != "") {
            ull target = stoull(temp);
            if (sieve(target)) ans++;
            temp = "";
        }
    }
    if (temp != "") {
        ull target = stoull(temp);
        if (sieve(target)) ans++;
    }
    return ans;
}

string change(ull n, ull k) {
    string str = "";
    while (n != 0) {
        str += (n % k) + '0';
        n /= k;
    }
    reverse(str.begin(), str.end());
    return str;
}

int solution(int n, int k) {
    int answer = findSieve(change(n, k));
    return answer;
}

int main(void) {
    cout << solution(437674, 3);
}