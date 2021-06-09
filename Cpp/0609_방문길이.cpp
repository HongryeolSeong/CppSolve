#include <string>
#include <iostream>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    return answer;
}

int main()
{
    string dirs = "LLLLLLR";
    int cntx = 0;
    int cnty = 0;
    int ix = 0;
    int iy = 0;
    int ry, rx;
    int res1 = 0;
    int res2 = 0;
    int res;
    int a[11][11] = { 0 };
    int mx[600] = { 0 };
    int my[600] = { 0 };
    int x = 5;
    int y = 5;

    for (int i = 0; i < dirs.size(); i++)
    {
        if (dirs[i] == 'U')
        {
            y--;
            if (y < 0)
            {
                y = 0;
                continue;
            }
            ry = (y + (y + 1)) + (x * 100);
            cnty++;
            my[iy++] = ry;
        }
        else if (dirs[i] == 'D')
        {
            y++;
            if (y > 10)
            {
                y = 10;
                continue;
            }
            ry = (y + (y - 1)) + (x * 100);
            cnty++;
            my[iy++] = ry;
        }
        else if (dirs[i] == 'L')
        {
            x--;
            if (x < 0)
            {
                x = 0;
                continue;
            }
            rx = (x + (x + 1)) + (y * 100);
            cntx++;
            mx[ix++] = rx;
        }
        else if (dirs[i] == 'R')
        {
            x++;
            if (x > 10)
            {
                x = 10;
                continue;
            }
            rx = (x + (x - 1)) + (y * 100);
            cntx++;
            mx[ix++] = rx;
        }
    }

    for (int i = 0; i < cntx; i++)
    {
        for (int j = 0; j < cntx; j++)
        {
            if (i == j) continue;      
            if (mx[i] == mx[j])          
            {
                mx[j] = -1;
            }
        }
    }

    for (int i = 0; i < cnty; i++)
    {
        for (int j = 0; j < cnty; j++)
        {
            if (i == j) continue;
            if (my[i] == my[j])
            {
                my[j] = -1;
            }
        }
    }

    for (int i = 0; i < cntx; i++)
    {
        if (mx[i] == -1) continue;
        res1++;
    }

    for (int i = 0; i < cnty; i++)
    {
        if (my[i] == -1) continue;
        res2++;
    }

    res = res1 + res2;

    cout << res;

    return 0;
}