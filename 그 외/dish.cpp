#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <string.h>
#pragma warning(disable:4996)
using namespace std;
#define ll long long int

ifstream fin("dish.inp");
ofstream fout("dish.out");

vector <char> dish;

int main() {


    int t;
    fin >> t;
    int size = 0;
    int sum = 10;
    char code = 0;

    for (int i = 0; i < t; i++) {

        fin >> size;
        for (int i = 0; i < size; i++) {
            fin >> code;
            dish.push_back(code);
        }

        for (int z = 0; z < dish.size() - 1; z++) {
            if (dish[z] != dish[z + 1]) {
                sum = sum + 10;
            }
            else
                sum = sum + 5;
        }
        fout << sum << '\n';
        sum = 10;
        dish.clear();
    }


    return 0;




}