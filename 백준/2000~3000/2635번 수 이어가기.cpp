#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> ve[30001];

int main(void)
{
	cin >> N;

	for (int i = N; i >= 0; i--) {
		int Temp = N;
		ve[i].push_back(N); ve[i].push_back(i);
		int count = 1;
		while (Temp - ve[i][count] > 0) {
			ve[i].push_back(Temp - ve[i][count]);
			Temp = ve[i][count];
			count++;
		}
	}

	int max = 0;
	int index = 0;
	for (int i = 0; i <= N; i++) {
		if (max < ve[i].size()) {
			max = ve[i].size();
			index = i;
		}
	}

	cout << max << '\n';
	for (int i = 0; i < ve[index].size(); i++) {
		cout << ve[index][i] << ' ';
	}

	return 0;
}