#include <iostream>
#include <algorithm>

using namespace std;

struct friends_pair {
	int a, b;
};

struct input_data {
	int n;
	friends_pair* pairs;
};

int arr[9];
bool fri[9][9]; // True 일시 싸움이 남


void solution(int n, friends_pair* pairs) {
	for (int i = 1; i <= 8; i++) arr[i - 1] = i;
	int ans = 0;
	do {
		bool flag = false;
		for (int i = 0; !flag && i < 7; i ++) {
			if (fri[arr[i]][arr[i + 1]]) flag = true;
		}
		if (!flag)ans++;
	} while (next_permutation(arr, arr + 8));
	cout << ans;
}

void process_stdin(input_data& inputData) {
	cin >> inputData.n;

	inputData.pairs = new friends_pair[inputData.n];

	for (int i = 0; i < inputData.n; i++) {
		cin >> inputData.pairs[i].a >> inputData.pairs[i].b;
		fri[inputData.pairs[i].a][inputData.pairs[i].b] = fri[inputData.pairs[i].b][inputData.pairs[i].a] = true;
	}
}

int main(void)
{
	input_data inputData;
	process_stdin(inputData);

	solution(inputData.n, inputData.pairs);

	return 0;
}