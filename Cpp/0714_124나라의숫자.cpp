#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    return answer;
}

int main()
{
    int n = 12;
    int a;
    int b;
    string base = "124";
    int cnt = 1;
    string answer;

    a = n / 3;
    b = n % 3;

    if (n > 3)
    {
        while (1)
        {
            if (a <= 4) break;
            a /= 3;
            cnt++;
        }
    }

    if (a == 4 && b == 0) cnt--;
    
    /*for (int i = 0; i < cnt + 1; i++)
    {
        answer.push_back();
    }*/

    return 0;
}