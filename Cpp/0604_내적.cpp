#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int i;
    int res = 0;

    for (i = 0; i < a.size(); i++)
    {
        res += a[i] * b[i];
    }

    return res;
}