#include <iostream>
#include <vector>

using namespace std;

int k[14]; int N;

void com(vector<int>& ve,int p) {
	if (ve.size() == 6) {
		for (int i = 0; i < ve.size(); i++) cout << ve[i] << ' ';
		cout << '\n';return;
	}
	for (int i = p; i < N; i++) {
		ve.push_back(k[i]);
		com(ve, i + 1);
		ve.pop_back();
	}

}

int main(void)
{
	while (1) {
		cin >> N;
		if (N == 0) break;
		for (int i = 0; i < N; i++) cin >> k[i];

		vector<int> ve;
		com(ve, 0);
		cout << '\n';
	}
	return 0;
}