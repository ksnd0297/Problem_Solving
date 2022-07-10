#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int leftArray[10001];
int rightArray[10001];

int N[10001];

int T;
int n;
int h;

int main(void)
{
	ifstream fin("shadow.inp");
	ofstream fout("shadow.out");

	fin >> T;
	while (T--) {
		fin >> n;
		for (int i = 0; i < n; i++) fin >> N[i];

		int max = 0;  
		for (int i = 0; i < n; i++) { // left -> right로 배열 지정
			if (max <= N[i]) {
				max = N[i];
				leftArray[i] = 0;
			}
			else leftArray[i] = max - N[i];
		}
		
		max = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (max <= N[i]) {
				max = N[i];
				rightArray[i] = 0;
			}
			else rightArray[i] = max - N[i];
		}
		
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (leftArray[i] == 0 || rightArray[i] == 0) continue;
			else ans += min({ leftArray[i], rightArray[i] });
		}
		fout << ans << '\n';
	}
	return 0;
}