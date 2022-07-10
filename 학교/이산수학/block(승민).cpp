#include <iostream>
#include <vector>
#include <fstream>
#pragma warning (disable:4996);
using namespace std;

int main() {
	freopen("block.inp", "r", stdin);
	freopen("block.out", "w", stdout);
	int n;
	cin >> n;
	int k;

	while (n--) {
		cin >> k;
		vector <vector<int>> arr(k);

		for (int i = 0; i < k; i++) {
			for (int j = 0; j <= i; j++) {
				int q = 0;
				cin >> q;
				arr[i].push_back(q);
			}
		}

		//위
		for (int i = k - 1; i > 0; i--) {
			for (int j = i; j > 0; j--) {
				if (arr[i - 1][j - 1] == -1) {
					if (arr[i][j] != -1 && arr[i][j - 1] != -1) {
						arr[i - 1][j - 1] = ((arr[i][j] + arr[i][j - 1]) + 100) % 100;
					}
				}

				if (arr[i][j] == -1) {
					if (arr[i - 1][j - 1] != -1 && arr[i][j - 1] != -1) {
						arr[i][j] = ((arr[i - 1][j - 1] - arr[i][j - 1]) + 100) % 100;
					}
				}
				if (arr[i][j - 1] == -1) {
					if (arr[i - 1][j - 1] != -1 && arr[i][j] != -1) {
						arr[i][j - 1] = ((arr[i - 1][j - 1] - arr[i][j]) + 100) % 100;
					}
				}



			}
		}

		//위
		for (int i = k - 1; i > 0; i--) {
			for (int j = i; j > 0; j--) {
				if (arr[i - 1][j - 1] == -1) {
					if (arr[i][j] != -1 && arr[i][j - 1] != -1) {
						arr[i - 1][j - 1] = ((arr[i][j] + arr[i][j - 1]) + 100) % 100;
					}
				}

				if (arr[i][j] == -1) {
					if (arr[i - 1][j - 1] != -1 && arr[i][j - 1] != -1) {
						arr[i][j] = ((arr[i - 1][j - 1] - arr[i][j - 1]) + 100) % 100;
					}
				}
				if (arr[i][j - 1] == -1) {
					if (arr[i - 1][j - 1] != -1 && arr[i][j] != -1) {
						arr[i][j - 1] = ((arr[i - 1][j - 1] - arr[i][j]) + 100) % 100;
					}
				}



			}
		}


		//아래
		for (int i = 0; i < k - 1; i++) {
			for (int j = 0; j < i; j++) {
				if (arr[i][j] == -1) {
					if (arr[i + 1][j] != -1 && arr[i + 1][j + 1] != -1) {
						arr[i][j] = (arr[i + 1][j + 1] + arr[i + 1][j] + 100) % 100;
					}
				}

				if (arr[i + 1][j + 1] == -1) {
					if (arr[i + 1][j] != -1 && arr[i][j] != -1) {
						arr[i + 1][j + 1] = (arr[i][j] - arr[i + 1][j] + 100) % 100;
					}
				}

				if (arr[i + 1][j] == -1) {
					if (arr[i][j] != -1 && arr[i + 1][j + 1] != -1) {
						arr[i + 1][j] = (arr[i][j] - arr[i + 1][j + 1] + 100) % 100;
					}
				}

			}
		}

		for (int i = 0; i < k - 1; i++) {
			for (int j = 0; j < i; j++) {
				if (arr[i][j] == -1) {
					if (arr[i + 1][j] != -1 && arr[i + 1][j + 1] != -1) {
						arr[i][j] = (arr[i + 1][j + 1] + arr[i + 1][j] + 100) % 100;
					}
				}

				if (arr[i + 1][j + 1] == -1) {
					if (arr[i + 1][j] != -1 && arr[i][j] != -1) {
						arr[i + 1][j + 1] = (arr[i][j] - arr[i + 1][j] + 100) % 100;
					}
				}

				if (arr[i + 1][j] == -1) {
					if (arr[i][j] != -1 && arr[i + 1][j + 1] != -1) {
						arr[i + 1][j] = (arr[i][j] - arr[i + 1][j + 1] + 100) % 100;
					}
				}

			}
		}




		for (int i = 0; i < k; i++) {
			for (int j = 0; j < arr[i].size(); j++) {
				cout << arr[i][j] << " ";
			}
			cout << '\n';
		}
	}
	return 0;
}