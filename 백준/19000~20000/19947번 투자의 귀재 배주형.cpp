#include <iostream>
#include <algorithm>

using namespace std;

int ans[11];

int main(void)
{
	int H, Y; cin >> H >> Y;
	ans[0] = H; 
	ans[1] = ans[0] * 1.05;
	ans[2] = ans[1] * 1.05;
	ans[3] = max((int)(ans[2] * 1.05), (int)(ans[0] * 1.2));
	ans[4] = max((int)(ans[3] * 1.05), (int)(ans[1] * 1.2));
	ans[5] = ans[0] * 1.35;

	for (int i = 6; i <= Y; i++) {
		ans[i] = ans[i - 1] * 1.05;
		ans[i] = max(ans[i], (int)(ans[i - 3] * 1.2));
		ans[i] = max(ans[i], (int)(ans[i - 5] * 1.35));
	}
	cout << ans[Y];
	return 0;
}