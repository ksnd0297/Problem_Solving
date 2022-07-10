#include <stdio.h>
#include <algorithm>
#pragma warning(disable : 4996)

using namespace std;

typedef struct traget {
	int x;
	int y;
}target;

target arr[100001];

bool compare(target arr1, target arr2) {
	if (arr1.y == arr2.y) {
		return arr1.x < arr2.x;
	}
	else {
		return arr1.y < arr2.y;
	}
}


int main() {
	int C; scanf("%d", &C);
	int x,y ;
	for (int i = 0; i < C; i++) {
		scanf("%d %d", &x, &y);
		arr[i].x = x;
		arr[i].y = y;
	}

	sort(arr + 0, arr + C, compare);
	
	for (int i = 0; i < C; i++) {
		printf("%d %d\n", arr[i].x, arr[i].y);
	}
	return 0;
}

