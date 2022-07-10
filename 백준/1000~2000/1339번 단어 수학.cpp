#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

string ans[9];
bool alphaCheck[26];
int alphaNum[26];

vector<int> permu;
vector<int> alpha;

int num = 9;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int C; cin >> C;
	int maxlen = 0;
	while (C--) {
		string temp; cin >> temp;
		reverse(temp.begin(), temp.end());
		if (maxlen < temp.size()) maxlen = temp.size();
		for (int i = 0; i < temp.size(); i++) {
			ans[i] += temp[i];
			if (!alphaCheck[temp[i] - 'A']) {
				alphaCheck[temp[i] - 'A'] = true;
				permu.push_back(num);
				num--;
				alpha.push_back(temp[i]);
			}
		}
	}
	int ret = 0;
	int max = 0;
	do {
		memset(alphaNum, 0, sizeof(alphaNum));
		for (int i = 0; i < alpha.size(); i++) alphaNum[alpha[i] - 'A'] = permu[i];

		ret = 0;
		int ten = 1;
		for (int i = 0; i < maxlen; i++) {
			int sum = 0;
			for (int j = 0; j < ans[i].size(); j++) {
				sum += alphaNum[ans[i][j] - 'A'];
			}
			ret += ten * sum;		
			ten *= 10;
		}
		if (max < ret) max = ret;
	} while (prev_permutation(permu.begin(), permu.end()));
	cout << max;

	return 0;
}