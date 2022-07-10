#include <stdio.h>
#include <math.h>
#define min(x,y) (x<y)?(x):(y)
#pragma warning(disable:4996)

int arr[50001]; 
int sqr[250];

int main() {	
	int N; scanf("%d", &N);
	arr[1] = 1;
	for (int i = 1; i <= sqrt(N) + 1; i++) sqr[i] = i * i;

	for (int i = 2; i <= N; i++) {
		arr[i] = 1 + arr[i - sqr[1]];
		for (int j = 1; j <= sqrt(i); j++) {
			arr[i] = min(arr[i], 1 + arr[i - sqr[j]]);
		}
		arr[i] = min(arr[i - 1] + 1, arr[i]);
	}
	printf("%d", arr[N]);
}