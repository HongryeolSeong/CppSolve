#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int i, j;
    int n;
    int answer[4][4];
    int val = 1;

    n = 4;

    for (i = 0; i < n; i++)
    {
        answer[0][i] = val++;
    }

    for (i = 1; i < n; i++)
    {
        answer[i][n - 1] = val++;
    }

    for (i = n - 2; i >= 0; i--)
    {
        answer[n - 1][i] = val++;
    }

    for (i = n - 2; i > 0; i--)
    {
        answer[i][0] = val++;
    }

    for (i = 1; i < n - 1; i++)
    {
        answer[1][i] = val++;
    }

    for (i = 2; i <= n - 2; i++)
    {
        answer[i][n - 2] = val++;
    }

    for (i = n - 3; i > 0; i--)
    {
        answer[n - 2][i] = val++;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << " " << answer[i][j];
        }
        cout << endl;
    }

    return 0;
}