#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string numbers) {
    int answer = 0;
    return answer;
}

int main()
{
    string n = "1234";
    string t;
    vector<int> ind;
    vector<int> all;
    vector<int> res;
    int k = 0;
    int temp;
    int cnt1 = 0;
    int cnt2 = 0;
    int zz = 0;

    sort(n.begin(), n.end());

    while (1)
    {
        ind.clear();
        k++;
        for (int i = 0; i < k; i++) {
            ind.push_back(1);
        }
        for (int i = 0; i < n.size() - k; i++) {
            ind.push_back(0);
        }
        sort(ind.begin(), ind.end());

        do
        {
            t.clear();

            for (int i = 0; i < ind.size(); i++)
            {
                if (ind[i] == 1)
                {
                    t += n[i];
                }
            }
            if (t[0] == '0') continue;
            all.push_back(atoi(t.c_str()));

        } while (next_permutation(ind.begin(), ind.end()));
        zz++;
        if (zz == n.size() - 1) break;
    }

    do
    {
        t.clear();

        for (int i = 0; i < n.size(); i++)
        {
            t += n[i];
        }
        if (t[0] == '0') continue;
        all.push_back(atoi(t.c_str()));

    } while (next_permutation(n.begin(), n.end()));

    for (int i = 0; i < all.size(); i++)
    {
        for (int j = 0; j < all.size(); j++)
        {
            if (i == j) continue;
            if (all[i] == all[j])
            {
                all[j] = -1;
            }
        }
    }

    for (int i = 0; i < all.size(); i++)
    {
        if (all[i] == -1) continue;
        res.push_back(all[i]);
    }

    for (int i = 0; i < res.size(); i++)
    {
        cnt1 = 0;
        for (int j = 1; j <= res[i]; j++)
        {
            if (res[i] % j == 0) cnt1++;
        }
        if (cnt1 == 2) cnt2++;
    }
    
    cout << cnt2;

    return 0;
}