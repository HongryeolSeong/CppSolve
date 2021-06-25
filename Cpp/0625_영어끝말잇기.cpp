#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n = 4;                                          // 끝말잇기에 참여한 인원
    vector<string> words = { "a", "aba", "aba", "a" };  // 검사할 끝말잇기 벡터<스트링>
    string t;                                           // 끝말잇기 단어를 잠시 담을 임시 스트링
    int idx = 0;                                        // 끝말잇기가 중단된 순서
    int flag = 0;                                       // 끝말잇기가 중단되어 탈락자가 나왔음을 나타내는 플래그
    vector<int> answer = { 0, 0 };                      // 경기 결과는 중단 안될경우를 대비하여
                                                        // [ 0, 0 ]로 초기화 한다.

    // 1. 끝말잇기가 중단되는지 판단한다.
    for (int i = 1; i < words.size(); i++)
    {
        t = words[i];                   // 한 단어를 잠시 담아 놓는다.
        for (int j = 0; j < i; j++)     // 해당 순서 바로 전까지 반복문을 돌려
        {                               // 그 전에 t단어와 같은 단어가 나왔는지 판단한다.

            if (t == words[j])          // 이전에 t단어와 같은 단어가 있다면
            {                           // 해당 인덱스(i)를 중단 인덱스로 설정한다.
                idx = i + 1;            // 벡터 인덱스는 0부터 시작하므로(0, 1, 2, ...) -> i
                                        // 1부터 시작하는 순서(1, 2, 3, 4, ...)인 중단 인덱스
                flag = 1;               
                break;
            }
        }

        if (flag == 1) break;

        if ((flag == 1) || (words[i].front() != words[i - 1].back()))
        {
            idx = i + 1;
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        if ((idx % n == 0) && (idx != 0))
        {
            answer[0] = n;
            answer[1] = idx / n;
        }
        else
        {
            answer[0] = idx % n;
            answer[1] = ((idx - (idx % n)) / n) + 1;
        }
    }
    
    cout << answer[0] << " " << answer[1];


    return 0;
}