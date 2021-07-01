#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n = 5;                      // 피보나치 수열의 인덱스
    vector<int> fibo;               // 피보나치 수열 벡터

    // 1. n번째 피보나치 수까지 피보나치 수열 생성한다.
    for (int i = 0; i <= n; i++)
    {
        if (i == 0)                 // 피보나치 0번째 수는 0으로 고정
        {
            fibo.push_back(0);
        }
        else if (i == 1 || i == 2)  // 피보나치 1, 2번째 수는 1로 고정
        {
            fibo.push_back(1);
        }
        else                        // 3번째 이상 피보나치 수는 앞의 두 수를 더해서 만든다.
        {
            fibo.push_back((fibo[i - 1] % 1234567) + (fibo[i - 2] % 1234567));
        }
    }

    // 피보나치 수마다 1234567 모듈러 연산을 하는 이유는
    // 44번째 피보나치 수만 가도 int의 범위를 넘어서므로
    // 피보나치 수마다 모듈러 연산을 하여 프로그램 실행에 있어서
    // int의 범위를 넘지 않은채로 계산 수행할 수 있도록 하기 위함이다.

    cout << fibo.back() % 1234567;

    return 0;
}