#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n = 5;
    vector<int> fibo;

    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
        {
            fibo.push_back(0);
        }
        else if (i == 1 || i == 2)
        {
            fibo.push_back(1);
        }
        else
        {
            fibo.push_back((fibo[i - 1] % 1234567) + (fibo[i - 2] % 1234567));
        }
    }

    cout << fibo.back() % 1234567;

    return 0;
}