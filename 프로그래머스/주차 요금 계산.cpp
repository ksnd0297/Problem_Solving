#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int carInTime[10001];
bool check[10001];

int carAllTime[10001];

int HourToMinute(string time) {
	int ret = 0;
	string temp = "";
	for (int i = 0; i < time.size(); i++) {
		if (time[i] != ':')temp += time[i];
		else {
			ret += stoi(temp) * 60;
			temp = "";
		}
	}
	return ret + stoi(temp);
}

vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> ret(10001);
	for (int i = 0; i < records.size(); i++) {
		string record[3] = { "", "", "" }; // 시간 차량번호 입출
		int index = 0;
		for (int j = 0; j < records[i].size(); j++) {
			if (records[i][j] != ' ') record[index] += records[i][j];
			else index++;
		}
		if(record[2] == "IN") {
			int time = HourToMinute(record[0]);
			int carNum = stoi(record[1]);
			check[carNum] = true;
			carInTime[carNum] = time;
		}
		else if (record[2] == "OUT") {
			int time = HourToMinute(record[0]);
			int carNum = stoi(record[1]);
			carAllTime[carNum] += time - carInTime[carNum];
			carInTime[carNum] = 0;
		}
	}

	int endTime = HourToMinute("23:59");
	for (int i = 0; i < 10000; i++) {
		if (carInTime[i] != 0) {
			carAllTime[i] += endTime - carInTime[i];
			carInTime[i] = 0;
		}
	}

	for (int i = 0; i < 10000; i++) {
		if (check[i]) {
			if (carAllTime[i] <= fees[0]) ret[i] = fees[1];
			else {
				ret[i] = fees[1] + ceil(((double)carAllTime[i] - (double)fees[0]) / (double)fees[2]) * fees[3];
			}
		}
	}
	vector<int> answer;
	for (int i = 0; i < 10000; i++) {
		if (check[i]) answer.push_back(ret[i]);
	}

	return answer;
}

int main(void)
{
	vector<int> fees; // 기본 시간 | 기본 요금 | 단위 시간 | 단위 요금
	vector<string> records;

	fees = { 180, 5000, 10, 600 };
	records = { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" };
	vector<int> answer = solution(fees, records);

	for (int i = 0; i < answer.size(); i++) {
		if (answer[i] != 0) cout << answer[i] << ' ';
	}

	return 0;
}