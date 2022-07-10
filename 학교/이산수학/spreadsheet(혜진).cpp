//
//  Copyright (c) 2021 HyeJin Shin All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#pragma warning(disable : 4996)

using namespace std;
char abc[27] ={' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("spreadsheet.inp","r",stdin);
    freopen("spreadsheet.out","w",stdout);
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        if(s[0]=='R'&&isdigit(s[1])!=0){  //string s가 R로 시작하고 s[1]이 숫자일 경우 (예, R23C55)
            bool key = false;
            string a = "";
            string b = "";
            for(int i=1;i<s.length();i++){
                if(isdigit(s[i])!=0&&!key){
                    a+=s[i];
                }
                else if(s[i]=='C'){key = true;}
                else {
                    b+=s[i];
                }
            }
            int num = stoi(b);
            string answer = "";
            answer += abc[num%26];
            while (1){
                if(num<27)break;
            num = num/26;
            answer += abc[num%26];
            }
            string aa="";
            for(int i=answer.length()-1;i>=0;i--){
                aa+=answer[i];
            }
            aa+=a;
            cout<<aa<<'\n';
        }
        else{  //BC23
            string ans="R";
            string col="";
            for(int i=0;i<s.length();i++){
                if(isdigit(s[i])!=0){
                    ans+=s[i];
                }
                else {
                    col+=s[i];
                }
            }
            ans+='C';
            int sum = 0;
            int p = col.length()-1;
            for(int i=0;i<col.length();i++){
                for(int j=1;j<=26;j++){
                    if(col[i]==abc[j]){
                        sum+=(pow(26,p)*j);
                    }
                }
                p--;
            }
            string sum2 = to_string(sum);
            ans+=sum2;
            cout<<ans<<'\n';
        }
    } //while
}

