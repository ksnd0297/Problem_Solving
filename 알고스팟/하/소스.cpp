#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <vector>
#include <algorithm>

using namespace std;

//ifstream cin("backspace.inp");
//ofstream cout("backspace.out");

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string a, b;
		cin >> a >> b;

		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		int b_cnt = 0;
		int m, n;
		if (a.length() < b.length())
		{
			cout << "NO" << endl; continue;
		}
		else
		{
			bool flag = false;
			for (m = 0; m < a.size(); m++)
			{
				flag = false;
				if (a[m] == b[b_cnt])
				{
					b_cnt++;
					if (b_cnt == b.size())
					{
						cout << "YES" << endl;
						flag = true;
						break;
					}
					else
						continue; // 한칸
				}
				else
				{
					for (n = m + 2; n < a.size(); n += 2)
					{
						if (a[n] == b[b_cnt])
						{
							m = n;
							b_cnt++;
							flag = true;
							break;
						}
					}

					if (flag == true) // 중간
					{
						if (b_cnt == b.size())
						{
							cout << "YES" << endl;
							break; //전체
						}
						else
							continue; //첫번째
					}
					else
					{
						break; // 끝까지
					}
				}
			}
			if (flag == false)
				cout << "NO" << endl;
		}
	}
}