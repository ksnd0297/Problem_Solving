#include <stdio.h>
#pragma warning(disable:4996)

int main(void)
{
	char* ary[3] = { (char*)"가위 ", (char*)"바위 ", (char*)"보 " };
	int num;

	while (1) {
		scanf("%d", &num);
		if (num == 0) break;
		if (num % 3 == 1) {
			printf("%s\n", ary[0]);
		}
		else if (num % 3 == 2) {
			printf("%s\n", ary[1]);
		}
		else if (num % 3 == 0) {
			printf("%s\n", ary[2]);
		}
	}
	return 0;
}