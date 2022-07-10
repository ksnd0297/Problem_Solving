#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
char arr[46][46];

bool check[25]; // -10 : 0 , 0 : 10, 10 : 20

string qus;

bool vali(vector<int>& ve) {
	
	
}

bool func(vector<int>& ve) {
	if (ve.size() == N) {
		for (int i = 0; i < N; i++) {
			cout << ve[i] << ' ';
		}
		return true;
	}

	for (int i = -10; i <= 10; i++) {
		ve.push_back(i);
		if (vali(ve)) {
			if (func(ve)) return true;
		}
		ve.pop_back();
	}
	return false;
}

int main(void) {
	cin >> N;
	cin >> qus;

	int length = N;
	int row = 0, index = 0;
	while (1) {
		if (row == N) break;
		for (int i = row; i < length; i++, index++) {
			arr[row][i] = qus[index];
		}
		 row++;
	}

	vector<int> ve;
	func(ve);

	return 0;
}