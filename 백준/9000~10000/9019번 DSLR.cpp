#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int T;
int A, B;

bool check[10001];

int D(int ret) {
	return (ret * 2) % 10000;
}

int S(int ret) {
	if (ret == 0) return 9999;
	else return ret - 1;
}

int L(int ret) {
	int one = ret / 1000;
	int two = ret % 1000 /100;
	int three = ret % 1000 %100 /10;
	int four = ret % 1000 % 100 % 10 /1;

	return two * 1000 + three * 100 + four * 10 + one;
}

int R(int ret) {
	int one = ret / 1000;
	int two = ret % 1000 / 100;
	int three = ret % 1000 % 100 / 10;
	int four = ret % 1000 % 100 % 10 / 1;

	return four * 1000 + one * 100 + two * 10 + three;
}

string func() {
	queue<pair<string, int>> q;
	q.push({ "", A });
	check[A] = true;
	do {
		if (q.front().second == B) return q.front().first;
		string str = q.front().first;
		int Num = q.front().second;
		q.pop();

		int Temp = 0;
		Temp = D(Num);
		if (!check[Temp]) {
			check[Temp] = true;
			q.push({ str + 'D', Temp });
		}
		Temp = S(Num);
		if (!check[Temp]) {
			check[Temp] = true;
			q.push({ str + 'S', Temp });
		}
		Temp = L(Num);
		if (!check[Temp]) {
			check[Temp] = true;
			q.push({ str + 'L', Temp });
		}
		Temp = R(Num);
		if (!check[Temp]) {
			check[Temp] = true;
			q.push({ str + 'R', Temp });
		}
	} while (!q.empty());
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--) {
		cin >> A >> B;
		cout << func() << '\n';
		memset(check, false, sizeof(check));
	}

	return 0;
}