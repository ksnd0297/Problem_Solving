#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
vector<string> K;

int T;
string W;

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		string temp; cin >> temp;
		K.push_back(temp);
	}

	cin >> T;
	while (T--) {
		cin >> W;
		int ans = 0;
		for (int i = 0; i < (int)K.size(); i++) { // SMNAME
			bool flag = false;
			for (int j = 0; !flag && j < (int)W.size(); j++) { //SM
				if (W[j] != K[i][j]) flag = true;
			}
			if (!flag)ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}