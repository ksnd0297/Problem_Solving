#include <iostream>
#include <vector>

using namespace std;

void normalize(vector<int>& num) {
	num.push_back(0);
	//자릿구 올림을 처리한다.
	for (int i = 0; i < num.size()-1; i++) {
		if (num[i] < 0) {
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] = borrow * 10;
		}
		else {
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	while (num.size() > 1 && num.back() == 0) num.pop_back();
}

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
	vector<int> c(a.size() + b.size() + 1, 0);
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			c[i + j] += a[i] * b[j];
		}
	}
	normalize(c);
	return c;
}

int main() {
	vector<int> a(3, 0);
	vector<int> b(3, 0);
	vector<int> c(6, 0);
	a = { 1,1,1 };
	b = { 2,2,2 };
	c = multiply(a, b);

	for (int i = 0; i < c.size(); i++) cout << c[i];

	return 0;
}