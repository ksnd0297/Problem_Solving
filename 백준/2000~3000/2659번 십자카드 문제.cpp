#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ve;

int main(void)
{
	int A, B, C, D;
	cin >> A >> B >> C >> D;

	int ans = min({
		A * 1000 + B * 100 + C * 10 + D,
		B * 1000 + C * 100 + D * 10 + A, 
		C * 1000 + D * 100 + A * 10 + B,
		D * 1000 + A * 100 + B * 10 + C 
		});

	for (int i = 1111; i <= 9999; i++) {
		string temp = to_string(i);
		if ((temp[0] - '0') == 0 || (temp[1] - '0') == 0 || (temp[2] - '0') == 0 || (temp[3] - '0') == 0) continue;

		int num = min({
			(temp[0] - '0') * 1000 + (temp[1] - '0') * 100 + (temp[2] - '0') * 10 + (temp[3] - '0') ,
			(temp[1] - '0') * 1000 + (temp[2] - '0') * 100 + (temp[3] - '0') * 10 + (temp[0] - '0') ,
			(temp[2] - '0') * 1000 + (temp[3] - '0') * 100 + (temp[0] - '0') * 10 + (temp[1] - '0') ,
			(temp[3] - '0') * 1000 + (temp[0] - '0') * 100 + (temp[1] - '0') * 10 + (temp[2] - '0') });
		
		ve.push_back(num);
	}

	sort(ve.begin(), ve.end());
	ve.erase(unique(ve.begin(), ve.end()), ve.end());

	for (int i = 0; i < ve.size(); i++) {
		if (ve[i] == ans) {
			cout << i + 1;
			break;
		}
	}

	return 0;
}