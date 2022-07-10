#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#pragma warning(disable:4996)

using namespace std;


int main() {
	int T; cin >> T;
	while (T--) {
		string qus; cin >> qus;
		int N; cin >> N;
		
		string arr; cin >> arr;
		deque<int> dq;

		string temp;
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] == '[') continue;
			else if (arr[i] >= '0' && arr[i] <= '9') temp += arr[i];
			else if (arr[i] == ',' || arr[i] == ']') {
				if (!temp.empty()) { dq.push_back(stoi(temp)); temp.clear();}
			}
		}
		bool rev = false; bool print = true;
		for (int i = 0; i < qus.size(); i++) {
			if (qus[i] == 'R') rev = !rev;
			else if(qus[i] == 'D') {
				if (dq.empty()) { print = false; cout << "error" << '\n'; break;}
				else {
					if (!rev) dq.pop_front();
					else dq.pop_back();
				}
			}
		}

		if (print) {
			if (!rev) {
				cout << "[";
				while (!dq.empty()) {
					cout << dq.front(); dq.pop_front();
					if (!dq.empty()) cout << ",";
				}
				cout << "]" << '\n';
			}
			else {
				cout << "[";
				while (!dq.empty()) {
					cout << dq.back(); dq.pop_back();
					if (!dq.empty()) cout << ",";
				}
				cout << "]" << '\n';
			}
		}
	}
	return 0;
}