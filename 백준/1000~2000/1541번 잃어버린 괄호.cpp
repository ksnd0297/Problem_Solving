#include <stdio.h>
#pragma warning(disable : 4996)

int main() {
	int num;
	char ch=0;
	bool flag = false;
	int ans = 0;
	while (ch != 10) {
		scanf("%d%c", &num, &ch);
		if (!flag) ans += num;
		else if (flag) ans -= num;
		if (ch == '-') flag = true;
	}
	printf("%d", ans);
	return 0;
}