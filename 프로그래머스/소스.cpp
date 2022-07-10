#include <string>
#include <vector>
#include <math.h>
#include <stack>
#include <limits.h>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

char ans[1000001];
int indx = 0;
void f(int m, int n)
{
	if (m == 0) return;
	f(m / n, n);
	ans[indx] = ((m % n)+ '0');
	indx++;
}


bool sieve(long long int num) {
	if (num < 2) return false;
	int a = (int)sqrt(num);
	for (int i = 2; i <= a; i++) if (num % i == 0) return false;
	return true;
}

int find(string ans) {
	istringstream ss(ans);
	vector<string> words;
	string word;
	int cnt = 0;
	while (getline(ss, word, '0')) words.push_back(word);
	for (int i = 0; i < words.size(); i++) {
		if (words[i] != "") {
			if (sieve(stoi(words[i]))) cnt++;
		}
	}
	return cnt;
}

int solution(int n, int k) {
	int answer = -1;
	f(n, k);
	answer = find(ans);
	return answer;
}

int main(void)
{
	int n, k; cin >> n >> k;
	f(n, k);
	cout << find(ans);
}