#include <iostream>

using namespace std;

int people[10000];
int dp[10000][2]; // Max : dp[X][0] Min dp[X][1]
int main(void)
{
	people[2] = 1; people[3] = 2;
	int a = 2; int b = 3;
	while (a + b <= 10000) {
		people[a + b] = people[a] + people[b];
		int temp = a; a = b;
		b = temp + b;
	}
	
	for (int i = 2; i <= 10000; i++) {
		
		for (int j = 2; j <= i / 2; j++) {

		}
	}
	return 0;
}