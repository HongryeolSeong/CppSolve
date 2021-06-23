#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N = 5;
    vector<vector<int>> r = { {1, 2, 1}, {2, 3, 3}, {5, 2, 2}, {1, 4, 2}, {5, 3, 1}, {5, 4, 2} };
    vector<vector<int>> near;
    //vector<vector<int>> near2;
    int K = 3;
    int route = 0;
    int cnt = 1;
    int ans = 1;
    int id = 0;

    while (1)
    {
        for (int i = id; i < r.size(); i++)
        {
            if (r[i][0] == 1 && r[i][2] <= K)
            {
                route += r[i][2];
                ans++;
                id = i;
                break;
            }
        }

        for (int i = 0; i < r.size(); i++)
        {

        }
    }

    //for (int i = 0; i < r.size(); i++)
    //{
    //    if (r[i][0] == 1)
    //    {
    //        if (r[i][2] <= K)
    //        {
    //            near.push_back({ r[i][1], r[i][2] });       // 1다리 마을 저장
    //            ans++;
    //        }
    //    }
    //}

    //for (int i = 0; i < near.size(); i++)
    //{
    //    if (r[i][1] == near[i][0] && (r[i][2] + near[i][1] <= K))
    //    {
    //        near2.push_back({r[i][0], r[i][1], r[i][2] });  // 2다리 마을 저장
    //        ans++;
    //    }
    //}
    
    cout << ans;

    return 0;
}