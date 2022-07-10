#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
	vector<int> ans;

	return ans;
}

int main(void)
{
	vector<vector<int> > v(3);
	v[0].push_back(1);
	v[0].push_back(4);
	v[1].push_back(3);
	v[1].push_back(4);
	v[2].push_back(3);
	v[2].push_back(10);
	vector<int> ans;


	for (int i = 0; i < v.size(); i++) {
		bool left = false;
		for (int j = 0; !left && j < v.size(); j++) {
			if (i == j) continue;
			if (v[i][0] == v[j][0]) {
				left = true; break;
			}
		}
		if (!left) {
			ans.push_back(v[i][0]);
			break;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		bool right = false;
		for (int j = 0; !right && j < v.size(); j++) {
			if (i == j) continue;
			if (v[i][1] == v[j][1]) {
				right = true; break;
			}
		}
		if (!right) {
			ans.push_back(v[i][1]);
			break;
		}
	}
	cout << ans[0] << ans[1] << '\n';
}