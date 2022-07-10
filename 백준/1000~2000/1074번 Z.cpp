#include <math.h>
#include <stdio.h>
#pragma warning(disable : 4996)

using namespace std;

int main() {
	int N, x, y; scanf("%d %d %d", &N, &y, &x);

	int len = (int)pow(2, N);

	int posx=0, posy=0;
	int ans = 0;
	while (N--) {
		if ((x >= posx && x <= posx + (len / 2 - 1)) && (y >= posy && y <= posy + (len / 2 - 1))) // 1 사분면
		{
			ans += (int)pow(4, N) * 0;
		}
		else if ((x >= posx + (len/2 - 1) && x <= posx + (len - 1)) && (y >= posy && y <= posy + (len / 2 - 1))) // 2 사분면
		{
			ans += (int)pow(4, N) *1;
			posx += len / 2;
		}
		else if ((x >= posx && x <= posx + (len / 2 - 1)) && (y >= posy+(len/2-1) && y <= posy + (len - 1))) // 3 사분면
		{
			ans += (int)pow(4, N) * 2;
			posy += len / 2;
		}
		else if ((x >= posx + (len / 2 - 1) && x <= posx + (len - 1)) && (y >= posy && y <= posy + (len - 1))) // 4 사분면
		{
			ans += (int)pow(4, N) * 3;
			posx += len / 2; posy += len / 2;
		}
		len /= 2;
	}
	printf("%d", ans);
}