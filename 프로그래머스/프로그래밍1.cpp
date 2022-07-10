#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> id_list;
vector<string> report;


bool arr[1001][1001];

void reporting(string ans, vector<string>& id_list) {
    int split = 0;
    string A, B;
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] == ' ') {
            A = ans.substr(i - split, split);
            split = 0;
        }
        else split++;
    }
    B = ans.substr(ans.size() - split, split);

    for (int i = 0; i < id_list.size(); i++) {
        if (id_list[i] == A) {
            for (int j = 0; j < id_list.size(); j++) {
                if (id_list[j] == B) {
                    arr[i][j] = true;
                }
            }
        }
    }
}

int main(void)
{
    id_list.push_back("muzi");
    id_list.push_back("frodo");
    id_list.push_back("apeach");
    id_list.push_back("neo");

    report.push_back("muzi frodo");
    report.push_back("apeach frodo");
    report.push_back("frodo neo");
    report.push_back("muzi neo");
    report.push_back("apeach muzi");
    int k = 2;

    for (int i = 0; i < report.size(); i++) reporting(report[i],id_list);
    vector<int> answer;
    int N = id_list.size();
    for (int i = 0; i < N; i++) {
        int ans = 0;
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == true) {
                int cnt = 0;
                for (int l = 0; l < N; l++) {
                    if (arr[l][j] == true) cnt++;
                }
                if(cnt >= k) ans++;
            }
        }
        answer.push_back(ans);
    }

    return 0;
}