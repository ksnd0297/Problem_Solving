#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int N, X; // N일 X 원
int A, B; // 5000원 짜리 A 1000원 짜리 B

vector<tuple<int, int, int>> menu;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		menu.push_back({ A - B, A, B });
	}
	sort(menu.begin(), menu.end(), greater<>());

	int ans = 0;
	for (int i = 0; X != 0 && i < menu.size(); i++) {
		if (get<0>(menu[i]) <= 0) { // 1000원 짜리가 더 맛이좋음
			ans += get<2>(menu[i]);
			X -= 1000;
		}
		else { // 5000원 짜리가 더 맛이좋음
			if (X >= 5000 && X - 5000 >= (menu.size() - i - 1) * 1000) { // 5000원을 빼도 괜찮을 때
				ans += get<1>(menu[i]);
				X -= 5000;
			}
			else {
				ans += get<2>(menu[i]);
				X -= 1000;
			}
		}
	}
	cout << ans;
	return 0;
}