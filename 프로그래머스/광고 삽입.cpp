#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long int logInfo[800001];
long long int sumInfo[800001];
vector<long long int> startTime;

long long int timetonum(long long int hour, long long int minute, long long int second) {
	long long int ans = 0;
	ans += hour * 60 * 60;
	ans += minute * 60;
	ans += second;
	return ans;
}

long long int mytime(string ans) {
	if (ans.size() == 17) { // logsInfo
		long long int a, b, c, d, e, f;
		a = ((ans[0] - '0') * 10) + ((ans[1] - '0') * 1);
		b = ((ans[3] - '0') * 10) + ((ans[4] - '0') * 1);
		c = ((ans[6] - '0') * 10) + ((ans[7] - '0') * 1);
		d = ((ans[9] - '0') * 10) + ((ans[10] - '0') * 1);
		e = ((ans[12] - '0') * 10) + ((ans[13] - '0') * 1);
		f = ((ans[15] - '0') * 10) + ((ans[16] - '0') * 1);

		long long int firstTime = timetonum(a, b, c);
		long long int secondTime = timetonum(d, e, f);
		startTime.push_back(firstTime);
		for (int i = firstTime+1; i <= secondTime; i++) logInfo[i]++;
		return 0;
	}
	else if (ans.size() == 8) { // play_time adv_time
		long long int a, b, c;
		a = ((ans[0] - '0') * 10) + ((ans[1] - '0') * 1);
		b = ((ans[3] - '0') * 10) + ((ans[4] - '0') * 1);
		c = ((ans[6] - '0') * 10) + ((ans[7] - '0') * 1);
		return timetonum(a, b, c);
	}
}

string timeToString(int sec) {
	long long int min, hour;
	min = sec / 60;
	hour = min / 60;
	sec = sec % 60;
	min = min % 60;
	string stringhour, stringmin, stringsec;
	if (hour < 10) stringhour = '0' + to_string(hour);
	else stringhour = to_string(hour);
	if (min < 10) stringmin = '0' + to_string(min);
	else stringmin = to_string(min);
	if (sec < 10) stringsec = '0' + to_string(sec);
	else stringsec = to_string(sec);
	string answer = stringhour + ':' + stringmin + ':' + stringsec;
	return answer;
}

string solution(string play_time, string adv_time, vector<string> logs) {
	long long int playtime = mytime(play_time);
	long long int advtime = mytime(adv_time);

	for (int i = 0; i < logs.size(); i++) long long int p = mytime(logs[i]);

	for (int i = 1; i <= playtime; i++) {
		sumInfo[i] = logInfo[i] + sumInfo[i-1];
	}

	long long int sec;
	long long int max = 0;
	for (int i = 0; i <= playtime; i++) {
		long long int adFirstTime = i;
		long long int adLastTime = i + advtime;
		if (adLastTime > playtime) break;
		long long int ans = 0;
		ans = sumInfo[adLastTime] - sumInfo[adFirstTime];
		if (max < ans) {
			max = ans;
			sec = i;
		}
	}
	string answer = timeToString(sec);
	return answer;
}

int main(void)
{
	string play_time = "99:59:59";
	string adv_time = "25:00:00";
	vector<string> logs;
	logs.push_back("69:59:59-89:59:59");
	logs.push_back("01:00:00-21:00:00");
	logs.push_back("79:59:59-99:59:59");
	logs.push_back("11:00:00-31:00:00");
	cout << solution(play_time, adv_time, logs);
	return 0;
}