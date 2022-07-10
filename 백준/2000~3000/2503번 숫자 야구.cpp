#include <iostream>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

vector<tuple<string, int, int>> qus; // Num S B
int N;

bool compare(const string& A) {
	int cnt = 0;
	for (int i = 0; i < qus.size(); i++) {
		int strike = 0, ball = 0;
		if (A[0] == get<0>(qus[i])[0]) strike++;
		else if (A[0] == get<0>(qus[i])[1] || A[0] == get<0>(qus[i])[2]) ball++;
		if (A[1] == get<0>(qus[i])[1]) strike++;
		else if (A[1] == get<0>(qus[i])[0] || A[1] == get<0>(qus[i])[2]) ball++;
		if (A[2] == get<0>(qus[i])[2]) strike++;
		else if (A[2] == get<0>(qus[i])[0] || A[2] == get<0>(qus[i])[1]) ball++;

		if (get<1>(qus[i]) == strike && get<2>(qus[i]) == ball) cnt++;
	}
	if (cnt == qus.size()) return true;
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	while (N--) {
		string num;
		int S, B;
		cin >> num >> S >> B;
		qus.push_back({ num, S, B });
	}

	int ans = 0;
	for (int i = 111; i <= 999; i++) {
		string temp = to_string(i);
		if (temp[0] == '0' || temp[1] == '0'|| temp[2] == '0') continue;
		if (temp[0] == temp[1] || temp[0] == temp[2] || temp[1] == temp[2]) continue;
		if (compare(to_string(i))) ans++;
	}
	cout << ans;
	return 0;
}