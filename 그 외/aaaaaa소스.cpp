#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

unordered_map<string> s1;
unordered_map<string> s2;

int solution(string str1, string str2) {
	for (int i = 0; i < str1.size(); i++) {
		str1[i] = tolower(str1[i]);
	}

	for (int i = 0; i < str2.size(); i++) {
		str2[i] = tolower(str2[i]);
	}
	int answer = 0;

	for (int i = 0; i < str1.size() - 1; i++) {
		if (str1[i] >= 'a' && str1[i] <= 'z' && str1[i + 1] >= 'a' && str1[i + 1] <= 'z') {
			string str = "";
			str += str1[i]; str += str1[i + 1];
			s1.push_back(str);
		}
	}

	for (int i = 0; i < str2.size() - 1; i++) {
		if (str2[i] >= 'a' && str2[i] <= 'z' && str2[i + 1] >= 'a' && str2[i + 1] <= 'z') {
			string str = "";
			str += str2[i]; str += str2[i + 1];
			s2.push_back(str);
		}
	}

	vector<string> Union = s1;
	vector<string>::iterator iter;
	for (iter = s2.begin(); iter != s2.end(); iter++) {
		Union.push_back(*iter);
	}

	int count = 0;
	for (iter = s2.begin(); iter != s2.end(); iter++) {
		if (s1.find(*iter) != s1.end()) {
			count++;
		}
	}

	return  ((double)count / Union.size()) * 65536;
}

int main(void) {
	cout << solution("aa1+aa2", "AAAA12");

	return 0;
}