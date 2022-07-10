#include <iostream>
#include <vector>
#include <string>

using namespace std;

int carIn[10001]; // <ÃâÀÔ>
int carTime[10001];
bool carCheck[10001];

void parse(string ans) {
	int split = 0;
	int time = 0;
	int carnum = 0;
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] == ' ') {
			string temp = ans.substr(i - split, split);
			if (temp.size() == 5) {
				int hour = stoi(temp.substr(0, 2));
				int minute = stoi(temp.substr(3, 5));
				time = hour * 60 + minute;
				split = 0;
			}
			else if (temp.size() == 4) {
				carnum = stoi(temp);
				split = 0;
			}
		}
		else split++;
	}
	string temp = ans.substr(ans.size() - split, split);
	if (temp == "IN") {
		carIn[carnum] = time;
		carCheck[carnum] = true;
	}
	else if (temp == "OUT") {
		carTime[carnum] += time - carIn[carnum];
		carIn[carnum] = 0;
		carCheck[carnum] = false;
	}
}

int main(void)
{

	fees.push_back(1);
	fees.push_back(461);
	fees.push_back(1);
	fees.push_back(10);


	//records.push_back("05:34 5961 IN");
	//records.push_back("06:00 0000 IN");
	//records.push_back("06:34 0000 OUT");
	//records.push_back("07:59 5961 OUT");
	//records.push_back("07:59 0148 IN");
	//records.push_back("18:59 0000 IN");
	//records.push_back("19:09 0148 OUT");
	//records.push_back("22:59 5961 IN");
	//records.push_back("23:00 5961 OUT");

	records.push_back("00:00 1234 IN");

	int endTime = 23 * 60 + 59;

	for (int i = 0; i < records.size(); i++) {
		parse(records[i]);
	}

	for (int i = 0; i < 10000; i++) {
		if (carCheck[i]) {
			carTime[i] += endTime - carIn[i];
		}
	}
	vector<int> answer;
	for (int i = 0; i < 10000; i++) {
		if (carCheck[i]) {
			int money = 0;
			money += fees[1];
			carTime[i] -= fees[0];
			if (carTime[i] > 0 && carTime[i] < fees[2]) {
				money += fees[3];
			}
			else if(carTime[i] > 0) {
				money += (carTime[i] / fees[2]) * fees[3];
				if (carTime[i] % fees[2] != 0) money += fees[3];
			}
			answer.push_back(money);
		}
	}
	for (int i = 0; i < answer.size(); i++) cout << answer[i] << '\n';
	return 0;
}