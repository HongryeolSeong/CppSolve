#include <string>
#include <vector>
#include <iostream>

using namespace std;

int makeFibo(int n);

int main() // ¤¾¤¾
{
    int n = 3;
    int fn;
    int answer;

    fn = makeFibo(5);
    answer = fn;

    cout << fn << '\n' << answer;

    return 0;
}

int makeFibo(int n)
{
    int fn;

    if (n == 2 || n == 1)
    {
        return 1;
    }
    else if (n == 0)
    {
        return 0;
    }
    else if (n > 2)
    {
        fn = makeFibo(n - 1) % 1234567 + makeFibo(n - 2) % 1234567;
        return fn;
    }
}