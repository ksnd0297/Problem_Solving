#include <iostream>
#include <algorithm>

using namespace std;

int freq[23];

bool compare(int i, int j)
{
	return j < i;
}

struct input_data {
	int n, k;
	int* numOfFrequenciesInRegion;
	int** frequencies;
};

void solution(int n, int k, int* numOfFrequenciesInRegion, int** frequencies) {
	int ans = 0;
	for (int i = 0; i < k; i++) {
		ans += freq[i];
	}
	cout << ans;
}

void process_stdin(input_data& inputData) {
	cin >> inputData.n >> inputData.k;

	inputData.numOfFrequenciesInRegion = new int[inputData.n];
	inputData.frequencies = new int* [inputData.n];

	for (int i = 0; i < inputData.n; i++) {
		int len;
		cin >> len;

		inputData.numOfFrequenciesInRegion[i] = len;
		inputData.frequencies[i] = new int[len];

		for (int j = 0; j < len; j++) {
			cin >> inputData.frequencies[i][j];
			freq[inputData.frequencies[i][j]]++;
		}
	}
	sort(freq, freq + 21, compare);
}

int main() {
	input_data inputData;
	process_stdin(inputData);

	solution(inputData.n, inputData.k, inputData.numOfFrequenciesInRegion, inputData.frequencies);

	return 0;
}