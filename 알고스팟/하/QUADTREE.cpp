#include <iostream>

#include <string>

using namespace std;



//쿼드 트리 뒤집기 문제를 해결하는 분할 정복 알고리즘

string reverse(string::iterator& it)

{

    char head = *it;

    ++it;

    //기저 사례: 1번 혹은 2번 과정일 경우

    if (head == 'b' || head == 'w')

        return string(1, head);

    //우선 각각의 칸을 뒤집는다(4분할된 칸들)

    string upperLeft = reverse(it); //4사분면

    string upperRight = reverse(it); //1사분면

    string lowerLeft = reverse(it); //2사분면

    string lowerRight = reverse(it); //3사분면



    //각각 위와 아래 조각들의 위치를 바꾼다(이래야 비로소 완전히 뒤집힌 것이다)

    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;

}



int main(void)

{

    int test_case;
    string picture;
    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        cin >> picture;

        string::iterator it = picture.begin();
        cout << reverse(it) << endl;

    }

    return 0;

}