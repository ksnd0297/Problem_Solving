#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, string>> map[11];

void com(string target, string ans, int N, int index) { // target string 중 N 개의 문자 뽑기
	if (ans.size() == N) {
		bool flag = false; // 없는 메뉴
		for (int i = 0; !flag && i < map[N].size(); i++) {
			if (map[N][i].second == ans) {
				map[N][i].first++;
				flag = true;
			}
		}
		if (!flag) map[N].push_back(make_pair(1, ans));
		return;
	}
	for (int i = index; i < target.size(); i++) {
		ans.push_back(target[i]);
		com(target, ans, N, i + 1);
		ans.pop_back();
	}
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	for (int i = 0; i < orders.size(); i++) {
		for (int j = 2; j <= orders[i].size(); j++) {
			sort(orders[i].begin(), orders[i].end());
			com(orders[i], "", j, 0);
		}
	}

	for (int i = 0; i < course.size(); i++) {
		sort(map[course[i]].begin(), map[course[i]].end(), greater<pair<int, string>>());
	}
	for (int i = 0; i < course.size(); i++) {
		if (map[course[i]].size() != 0) {
			int maxCount = map[course[i]][0].first;
			for (int j = 0; j < map[course[i]].size(); j++) {
				if (maxCount == map[course[i]][j].first && maxCount != 1) answer.push_back(map[course[i]][j].second);
				else break;
			}
		}
	}
	sort(answer.begin(), answer.end());
	return answer;
}