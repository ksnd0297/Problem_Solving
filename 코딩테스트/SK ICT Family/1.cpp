#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int money;
vector<int> coin;
vector<int> cost; // 1 5 10 50 100 500
vector<int> gap;

vector<pair<int, int>> temp; // coin 과 coin - gap 이 담김

int solution(int money, vector<int> cost) {
	coin = { 1,5,10,50,100,500 };
	int answer = 0;
	// 4578
	for (int i = 0; i < 6; i++) {
		gap.push_back(coin[i] - cost[i]);
	}

	for (int i = 0; i < 6; i++) {
		temp.push_back({coin[i] + gap[i], coin[i]});
	}
	
	sort(temp.begin(), temp.end(), greater<pair<int,int>>());


	for (int i = gap.size() -1; i >= 0; i--) {
		if (gap[i] >= 0) { // gap이 양수 즉, 만들면 손해를 안볼 때
			answer += (money / coin[i]) * cost[i];
			money -= (money / coin[i]) * coin[i];
		}
	}

	// 손해보지 않고 돈을 만듬 후에 손해를 보며 돈을 만들어야함
	for (int i = 0; i < temp.size(); i++) {
		answer += (money / temp[i].second) * (temp[i].second + (temp[i].second - temp[i].first));
		money -= (money / temp[i].second) * temp[i].second;
	}


	return answer;
}

int main(void)
{
	money = 1999;
	cost = {2,11,20,100,200,600 };

	cout << solution(money, cost);

	return 0;
}