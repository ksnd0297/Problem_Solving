#include <iostream>
using namespace std;

int main(void)
{

  
    int N; cin >> N;
    if (N % 2 == 0) cout << (long long int)(N / 2) * (N - 1);
    else cout << (long long int)N * ((N - 1) / 2);
    return 0;
}