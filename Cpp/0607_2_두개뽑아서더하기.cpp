#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    //vector<int> a = { 2, 1, 3, 4, 1 };    // 일반적인 경우
    vector<int> a = { 0, 0, 0 };            // 0만 넣은 경우
    vector<int> b;                          // a벡터 요소들을 더해서 만든 벡터(중복 존재)
    vector<int> c;                          // b벡터에서 중복되는 요소들을 뺀 벡터(최종)

    int i, j;                               // 반복문용
    int temp;                               // 정렬속 swap용

    // 1. a백터의 요소들을 서로서로 싹다 더한 후
    //    b벡터에 대입한다.
    for (i = 0; i < a.size(); i++)
    {
        for (j = 0; j < a.size(); j++)
        {
            if (i == j) continue;       // i = 1, j = 1이어서
                                        // a[1] + a[1]인 경우를 스킵한다.

            b.push_back(a[i] + a[j]);   // a = { 1, 2, 3 } 인경우
                                        // b = { 3, 4, 3, 5, 4, 5 }가 된다.
        }
    }

    // b벡터 확인용
    for (i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }

    cout << endl;

    // 2. b벡터 속 중복된 값을 가지는 요소들을 -1로 처리한다.
    for (i = 0; i < b.size(); i++)
    {
        for (j = 0; j < b.size(); j++)
        {
            if (i == j) continue;       // b[1]과 b[1]을 비교하는 경우는 스킵
            if (b[i] == b[j])           // b요소들을 서로 비교하여 같은 경우
            {
                b[j] = -1;              // 둘 중 하나의 요소를 -1로 치환
                                        // [1, 0, 2, 1]인 경우
                                        // [1, 0, 2, -1]로 바꿔준다
            }
        }
    }

    // 3. b벡터에서 -1을 제외한 모든 요소들을 받아온다.
    for (i = 0; i < b.size(); i++)
    {
        if (b[i] != -1)
        {
            c.push_back(b[i]);      // b = { 1, 0, 2, -1 }인 경우
                                    // c = { 1, 0, 2 }가 된다.
        }
    }

    // 4. 마지막으로 c벡터의 요소들을 오름차순으로 정렬한다.
    for (i = 1; i < c.size(); i++)
    {
        for (j = i; j > 0; j--)
        {
            if (c[j] < c[j - 1])
            {
                temp = c[j];
                c[j] = c[j - 1];
                c[j - 1] = temp;
            }
        }
    }

    // c벡터 확인용
    for (i = 0; i < c.size(); i++)
    {
        cout << c[i] << " ";
    }

    return 0;
}