#include <stdio.h>
#pragma warning(disable: 4996)

int arr[1000001];
char check[1000001];

int top = 0; // Top의 Index = 0

int main() {
	int N; scanf("%d", &N); // 케이스
	
	int num;
	int index = 0; // check의 인덱스
	bool flag = false; // NO의 경우
	int su = 1; // 수열의 시작 : 1

	while (N--) {
		scanf("%d", &num);
		for (;su <= num;su++) {
			check[index++] = '+';
			arr[top++] = su; 
		}
		if (arr[top-1] == num) {
			top--; check[index++] = '-';
		}
		else if (arr[top-1] != num) {
			flag = true; break;
		}
	}

	if (flag) printf("NO\n");
	else {
		for (int i = 0; i < index; i++) printf("%c\n", check[i]);
	}
}