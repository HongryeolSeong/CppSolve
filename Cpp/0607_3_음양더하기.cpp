#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> a = { 1, 2, 3 };                // 정수 벡터
    vector<bool> s = { false, false, true };    // 부호 벡터(bool형)
    vector<int> is;                             // 부호 벡터(int형)
    int i;                                      // 반복문용
    int res = 0;                                // 최종 반환 변수

    // 1. s벡터의 bool 값을 이용하여 is벡터의 정수값(1 or -1) 생성
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == true)       // s벡터가 true인 경우 is는 1
        {
            is.push_back(1);
        }
        else if (s[i] == false) // s벡터가 false인 경우 is는 -1
        {
            is.push_back(-1);
        }
    }

    // is벡터 확인용
    for (i = 0; i < is.size(); i++)
    {
        cout << is[i] << " ";
    }

    cout << endl;

    // 2. is벡터의 1(or -1)값을 이용하여 부호가 있는 정수로 변환
    for (i = 0; i < a.size(); i++)
    {
        a[i] *= is[i];
    }

    // a벡터 확인용
    for (i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    // 3. res에 a벡터의 값들을 더하여 최종 반환값 만들기
    for (i = 0; i < a.size(); i++)
    {
        res += a[i];
    }

    // res 확인용
    cout << res;

    return 0;
}