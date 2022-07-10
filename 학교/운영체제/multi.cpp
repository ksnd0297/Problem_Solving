#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <climits>
#pragma warning(disable : 4996)

using namespace std;

vector <int> idle;

int N, t;
int inpArr[1004][101];
int ioArr[1004];
int cpuTime, ioChk, curCpu, idleTime;
bool lastIoInp;
bool lastCpuIoChk; // true 일 때 마지막이 cpu, false 일 대 마지막이 io

int zero;

int main(void) {
    freopen("multi.inp", "r", stdin);
    freopen("multi.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0;; j++)
        {
            cin >> t;
            if (t == 0) {
                zero++;
            }
            if (t == -1) {
                inpArr[i][j] = -1;
                break;
            }
            else inpArr[i][j] = t;
        }
    }

    int finishCnt = 0;
    while (1) {
        bool flag = false;
        if (finishCnt == N) break;
        for (int y = 0; !flag && y < N; y++)
        {
            if (curCpu >= ioArr[y]) {
                for (int x = 0; !flag; x++)
                {
                    if (inpArr[y][x] != 0) {
                        if (x % 2 == 0) { // cpu 사용량 처리 부분
                            if (inpArr[y][x] == -1) {
                                ioArr[y] = INT_MAX;
                                flag = true;
                                //inpArr[y][x] = 0;
                                finishCnt++;
                                break;
                            }
                            curCpu += inpArr[y][x];
                            lastCpuIoChk = true;
                            inpArr[y][x] = 0;
                        }
                        else { // io 사용량 처리 부분
                            if (inpArr[y][x] == -1) {
                                ioArr[y] = INT_MAX;
                                //inpArr[y][x] = 0;
                                flag = true;
                                finishCnt++;
                                break;
                            }
                            ioArr[y] = curCpu + inpArr[y][x];
                            inpArr[y][x] = 0;
                            lastCpuIoChk = false;
                            flag = true;
                            break;
                        }
                    }
                }
            }
            else continue;

            bool wholeChk = true;
            lastIoInp = true;
            int ioMin = INT_MAX;
            for (int i = 0; i < N; i++) // 모든 프로세스가 다 IO 인 것 체크하는 부분
            {
                if (ioArr[i] <= curCpu) wholeChk = false;
                if (ioArr[i] != INT_MAX) lastIoInp = false;
                ioMin = min(ioMin, ioArr[i]);
            }
            if (!wholeChk) break;

            if (wholeChk) { // 모든 프로세스가 다 IO 일 때
                if (ioMin != INT_MAX) {
                    idleTime = idleTime + ioMin - curCpu;
                    idle.push_back(ioMin - curCpu);
                    curCpu = ioMin;
                }
            }

        }
        lastIoInp = true;
        for (int tz = 0; tz < N; tz++)
        {
            if (ioArr[tz] != INT_MAX) {
                lastIoInp = false;
                break;
            }
        }
        if (lastIoInp) break;
    }


    if (lastIoInp && !idle.empty() && !lastCpuIoChk) {
        idleTime -= idle.back();
    }

    cout << idleTime << ' ' << curCpu << ' ';
    return 0;
}