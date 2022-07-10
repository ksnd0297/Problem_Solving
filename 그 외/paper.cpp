#include <iostream>
#include <fstream>

using namespace std;

int T;
int N, M;

int height[51][51]; // 세로 선
int width[51][51]; // 가로 선

int main(void)
{
	ifstream fin("paper.inp");
	ofstream fout("paper.out");
	fin >> T;
	fout << '\n' << T << '\n';
	while (T--) {
		fin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M - 1; j++) {
				fin >> height[i][j];
			}
		}

		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < M; j++) {
				fin >> width[i][j];
			}
		}

		bool flag = false;
		for (int i = 0; !flag && i < N - 1; i++) {
			for (int j = 0; !flag && j < M - 1; j++) {
				if ((height[i][j] == height[i + 1][j] && width[i][j] == width[i][j + 1]) || (height[i][j] != height[i+1][j] && width[i][j] != width[i][j+1])) flag = true;
			}
		}
		flag ? fout << 0 : fout << 1;
		fout << ' ';
	}
	fin.close();
	fout.close();
	return 0;
}