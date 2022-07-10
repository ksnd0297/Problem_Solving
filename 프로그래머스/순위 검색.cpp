#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> people[3][2][2][2];

void getInfo(string ans) {
	int l, g, c, f;
	int split = 0;
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] == ' ') {
			string temp = ans.substr(i - split, split);
			if (temp == "cpp") l = 0;
			else if (temp == "java") l = 1;
			else if (temp == "python") l = 2;
			else if (temp == "backend") g = 0;
			else if (temp == "frontend") g = 1;
			else if (temp == "junior") c = 0;
			else if (temp == "senior") c = 1;
			else if (temp == "chicken") f = 0;
			else if (temp == "pizza")  f = 1;
			split = 0;
		}
		else split++;
	}
	people[l][g][c][f].push_back(stoi(ans.substr(ans.size() - split, split)));
}

void getquery(string ans, vector<int>& answer) {
	int l, g, c, f;
	int split = 0;
	int cnt = 0;
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] == ' ') {
			string temp = ans.substr(i - split, split);
			if (temp == "cpp") { l = 0; cnt++; }
			else if (temp == "java") { l = 1; cnt++; }
			else if (temp == "python") { l = 2; cnt++; }
			else if (temp == "backend") { g = 0; cnt++; }
			else if (temp == "frontend") { g = 1; cnt++; }
			else if (temp == "junior") { c = 0; cnt++; }
			else if (temp == "senior") { c = 1; cnt++; }
			else if (temp == "chicken") { f = 0; cnt++; }
			else if (temp == "pizza") { f = 1; cnt++; }
			else if (temp == "-") {
				switch (cnt) {
				case 0: l = 3; break;
				case 1: g = 3; break;
				case 2: c = 3; break;
				case 3: f = 3; break;
				}
				cnt++;
			}
			split = 0;
		}
		else split++;
	}
	int number = stoi(ans.substr(ans.size() - split, split));
	int count = 0;
	for (int i = 0; i < 3; i++) {
		if (i == l || l == 3) {
			for (int j = 0; j < 2; j++) {
				if (j == g || g == 3) {
					for (int k = 0; k < 2; k++) {
						if (c == k || c == 3) {
							for (int l = 0; l < 2; l++) {
								if (f == l || f == 3) {
									for (int n = 0; n < people[i][j][k][l].size(); n++) {
										if (people[i][j][k][l][n] >= number) count++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	answer.push_back(count);
}

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	for (int i = 0; i < info.size(); i++) getInfo(info[i]);
	for (int i = 0; i < query.size(); i++) getquery(query[i], answer);
	return answer;
}