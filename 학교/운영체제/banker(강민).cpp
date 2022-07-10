#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int n, m;
int sysmax[51];
int maxarr[51][51];
int allocation[51][51];
int available[51];
int tmpavailable[51];
int need[51][51];
int tmpneed[51][51];
int tmparr[51][51];
queue<int>wait;
string comm;

int main() {
	const char* input_file = "banker.inp";
	const char* output_file = "banker.out";
	ifstream readFile(input_file);
	ofstream writeFile(output_file);
	if (readFile.is_open()) {
		while (!readFile.eof()) {
			readFile >> n >> m;
			for (int i = 0; i < m; i++) readFile >> sysmax[i];
			for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) readFile >> maxarr[i][j];
			for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) readFile >> allocation[i][j];
			for (int i = 0; i < m; i++) {
				int sum = 0;
				for (int j = 0; j < n; j++) sum += allocation[j][i];
				available[i] = sysmax[i] - sum;
			}
			for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) need[i][j] = maxarr[i][j] - allocation[i][j];
			//여기까지는 입력 & 초기화
			while (1) {
				int pnum;
				readFile >> comm;
				if (comm == "request") {
					bool check = true;
					bool check2 = true;
					readFile >> pnum;
					for (int i = 0; i < m; i++) {
						readFile >> tmparr[pnum][i];
						if (tmparr[pnum][i] > need[pnum][i]) check = false;
					}
					if (check) {
						for (int i = 0; i < m; i++) if (tmparr[pnum][i] > available[i]) check2 = false;
						if (check2) {
							for (int i = 0; i < m; i++) {
								available[i] -= tmparr[pnum][i];
								need[pnum][i] -= tmparr[pnum][i];
								allocation[pnum][i] += tmparr[pnum][i];
							}
							for (int i = 0; i < m; i++) tmpavailable[i] = available[i];
							for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) tmpneed[i][j] = need[i][j];
							bool isp = true;
							bool flag = true;
							int count = 0;
							int countn = 0;
							while (1) {
								for (int i = 0; i < n; i++) {
									int cnt = 0;
									int sum = 0;
									for (int j = 0; j < m; j++) sum += tmpneed[i][j];
									if (sum != -1 * m) {
										for (int j = 0; j < m; j++) if (tmpneed[i][j] <= tmpavailable[j]) cnt += 1;
										if (cnt == m) {
											for (int j = 0; j < m; j++) {
												tmpneed[i][j] = -1;
												tmpavailable[j] += allocation[i][j];
											}
											count++;
											break;
										}
										else {
											flag = false;
											countn++;
										}
									}
									else continue;
								}
								if (countn == n) {
									isp = false;
									break;
								}
								if (count == n) {
									isp = true;
									break;
								}
							}
							if (!isp) {
								for (int i = 0; i < m; i++) {
									available[i] += tmparr[pnum][i];
									need[pnum][i] += tmparr[pnum][i];
									allocation[pnum][i] -= tmparr[pnum][i];
								}
								wait.push(pnum);
							}
						}
						else {
							wait.push(pnum);
						}
					}
					for (int i = 0; i < m; i++) writeFile << available[i] << ' ';
					writeFile << '\n';
				}
				else if (comm == "release") {
					bool check2 = true;
					readFile >> pnum;
					for (int i = 0; i < m; i++) {
						readFile >> tmparr[pnum][i];
						if (tmparr[pnum][i] > allocation[pnum][i]) check2 = false;
					}
					if (check2) {
						for (int i = 0; i < m; i++) {
							available[i] += tmparr[pnum][i];
							allocation[pnum][i] -= tmparr[pnum][i];
							need[pnum][i] += tmparr[pnum][i];
						}
					}
					int x = wait.size();
					for (int i = 0; i < x; i++) {
						if (wait.empty()) break;
						bool check = true;
						pnum = wait.front();
						wait.pop();
						for (int i = 0; i < m; i++) if (tmparr[pnum][i] > available[i]) check = false;
						if (check) {
							for (int i = 0; i < m; i++) {
								available[i] -= tmparr[pnum][i];
								need[pnum][i] -= tmparr[pnum][i];
								allocation[pnum][i] += tmparr[pnum][i];
							}
							for (int i = 0; i < m; i++) tmpavailable[i] = available[i];
							for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) tmpneed[i][j] = need[i][j];
							bool isp = true;
							bool flag = true;
							int count = 0;
							int countn = 0;
							while (1) {
								for (int i = 0; i < n; i++) {
									int cnt = 0;
									int sum = 0;
									for (int j = 0; j < m; j++) sum += tmpneed[i][j];
									if (sum != -1 * m) {
										for (int j = 0; j < m; j++) if (tmpneed[i][j] <= tmpavailable[j]) cnt += 1;
										if (cnt == m) {
											for (int j = 0; j < m; j++) {
												tmpneed[i][j] = -1;
												tmpavailable[j] += allocation[i][j];
											}
											count++;
											break;
										}
										else {
											flag = false;
											countn++;
										}
									}
									else continue;
								}
								if (countn == n) {
									isp = false;
									break;
								}
								if (count == n) {
									isp = true;
									break;
								}

							}
							if (!isp) {
								for (int i = 0; i < m; i++) {
									available[i] += tmparr[pnum][i];
									need[pnum][i] += tmparr[pnum][i];
									allocation[pnum][i] -= tmparr[pnum][i];
								}
								wait.push(pnum);
							}
						}
						else {
							wait.push(pnum);
						}

					}
					for (int i = 0; i < m; i++) writeFile << available[i] << ' ';
					writeFile << '\n';
				}
				else if (comm == "quit") break;
			}
		}
		readFile.close();
	}

}