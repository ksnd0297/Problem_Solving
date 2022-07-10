#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

ifstream fin("multi.inp");
ofstream fout("multi.out");



int main() {

    int num = 0;
    int c = 0;
    int o = 0;
    int max = 1;
    int ca_p = 0;
    int ca_m = 0;
    int mo = 0;
    int r = 0;
    fin >> num;
    for (int i = 0; i < num; i++) {
        fin >> c;

        vector <int> all;
        ca_p = 0;
        ca_m = 0;

        for (int k = 0; k < c; k++) {
            fin >> o;
            all.push_back(o);
            if (o < 0) mo++;
        }

        sort(all.begin(), all.end());

        for (int z = 0; z < 5; z++) {
            max = max * all[z];

        }


        if (mo >= 2) {
            r = all[0] * all[1] * all[all.size() - 1] * all[all.size() - 2] * all[all.size() - 3];
            if (r > max) {
                max = r;
            }
            r = all[0] * all[1] * all[2] * all[3] * all[all.size() - 1];
            if (r > max) {
                max = r;
            }
        }
        if (mo < 2) {
            for (int z = 0; z < 5; z++) {
                max = max * all[all.size() - z - 1];

            }
        }


        fout << max << '\n';
        mo = 0;
        max = 1;
    }

    return 0;
}