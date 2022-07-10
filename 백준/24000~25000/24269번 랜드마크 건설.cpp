#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> S;

int main(void)
{
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int Num; cin >> Num;
		S.push_back(Num);
	}

	return 0;
}