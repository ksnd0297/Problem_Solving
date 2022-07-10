#include <iostream>
#include <algorithm>
#include <string.h>
#define ll long long int

using namespace std;

ll C;
ll N;
ll arr[100001];

ll ans(ll start, ll end) { // ans(start, end/2-1), ans(end/2, end)
	ll leftMax = 0, rightMax = 0, midMax = 0;
	if (start >= end) return arr[start];
	leftMax = max(leftMax, ans(start, (start + end) / 2));
	rightMax = max(rightMax, ans((start + end) / 2 + 1, end));

	ll length = 1;
	ll height = arr[(start + end) / 2];
	midMax = height * length;
	ll left = ((start + end) / 2) - 1;
	ll right = ((start + end) / 2) + 1;
	while (1) {
		if (left == start - 1 && right == end + 1) break;
		else if ((arr[left] >= arr[right] && left >= start) || (right == end +1)) {
			length++;
			if (height > arr[left]) height = arr[left];
			midMax = max(midMax, height * length);
			left--;
		}
		else if ((arr[left] < arr[right] && right <= end) || (left == start - 1)) {
			length++;
			if (height > arr[right]) height = arr[right];
			midMax = max(midMax, height * length);
			right++;
		}
	}
	return max({ leftMax, rightMax, midMax });
}

int main(void)
{
	while (1) {
		cin >> N;
		if (N == 0) break;
		for (int i = 0; i < N; i++) cin >> arr[i];
		cout << ans(0, N - 1) << '\n';
	}
	return 0;
}