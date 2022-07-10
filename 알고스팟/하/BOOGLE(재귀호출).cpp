#include <stdio.h>
#include <Windows.h>

int main(void)
{
	ULONG64 aa;
	ULONG64 bb;
	scanf("%lld %lld", &aa, &bb);
	printf("%lld", aa + bb);
	return 0;
}