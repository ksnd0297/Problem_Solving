#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#pragma warning(disable: 4996)

#define MAX(x,y) (x>y)?(x):(y);
#define MIN(x,y) (x<y)?(x):(y);

using namespace std;

int freq[8001];
int point[8001];

vector<int> vec;

int frequency();

int main() {
	int N; scanf("%d", &N);


	int max = -4444;
	int min = 4444;

	int num;
	double sum = 0;

	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		if (num <= 0) {
			int ab = abs(num);
		}

		vec.push_back(num);
		sum += num; // 산술 평균
		max = MAX(max, num); // 범위
		min = MIN(min, num); // 범위
	}


	sort(vec.begin(), vec.end()); // 중앙값

	for (int i = 0; i < vec.size(); i++) {freq[vec[i] + 4000]++;} // 0 ~ 8000 -> -4000 ~ 4000 에 4000을 더한 값

	int mode = frequency();

	printf("%.0lf\n", floor((sum /N)+0.5));
	printf("%d\n", vec[N / 2]);
	printf("%d\n", mode);
	printf("%d\n", max - min);
}

int frequency() {
	int maxfreq = 0;
	int maxfreqindex = 0;
	for (int i = 0; i <= 8000; i++) { // 최대 최빈 값 생성
		if (maxfreq <= freq[i]) {
			maxfreq = freq[i];
			maxfreqindex = i;
		}
	}

	int index = 0;
	for (int i = 0; i <= maxfreqindex; i++) { // 중복 확인
		if (maxfreq == freq[i]) {
			point[index++] = i;
		}
	}

	if (index == 1) {
		if (maxfreqindex <= 4000) return (4000 - maxfreqindex)*-1;
		else return maxfreqindex - 4000;
	}
	else{
		if (point[1] <= 4000) return (4000-point[1])*-1;
		else return point[1] - 4000;
	}
	return 0;
}
