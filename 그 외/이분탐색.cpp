#include <iostream>
#include <vector>

using namespace std;

vector<int> ve = { 1,2,3,4,5,6,7,8,9,10 };

int binarySearch(int start, int end, int target) {
	int mid = (start + end) / 2;
	if (ve[mid] == target) return mid;

	if (ve[mid] > target) return binarySearch(start, mid - 1, target);
	else if (ve[mid] < target) return binarySearch(mid + 1, start, target);
}

int lowerBound(int start, int end, int target) { // 찾고자 하는 값 이상이 처음 나타나는 위치
	if (start == end) return start;
	int mid = (start + end) / 2;


	if (ve[mid] < target) return lowerBound(mid + 1, end, target);
	else return lowerBound(start, mid, target);
}

int upperBound(int start, int end, int target) { // 찾고자 하는 값 초과 처음 나타나는 위치
	if (start == end) return start;
	int mid = (start + end) / 2;

	if (ve[mid] <= target) return upperBound(mid + 1, end, target);
	else return upperBound(start, mid, target);
}

int main(void) {

	return 0;
}