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
    string n = "011";
    string t;
    vector<int> in;
    vector<int> ind;
    int temp;
    int cnt1 = 0;
    int cnt2 = 0;

    sort(n.begin(), n.end());

    /*for (int i = 0; i < n.size(); i++)
    {
        in.push_back(n[i] - 48);
        cnt1 = 0;
        for (int j = 1; j <= in[i]; j++)
        {
            if (in[i] % j == 0) cnt1++;
            if (cnt1 == 2) cnt2++;
        }
    }*/

    for (int i = 0; i < 1; i++) {
        ind.push_back(1);
    }
    for (int i = 0; i < n.size() - 1; i++) {
        ind.push_back(0);
    }
    sort(ind.begin(), ind.end());

    do
    {
        t.clear();
        cnt1 = 0;

        for (int i = 0; i < ind.size(); i++)
        {
            if (ind[i] == 1)
            {
                t += n[i];
            }
        }
        if (t[0] == '0') continue;
        temp = atoi(t.c_str());

        for (int i = 1; i <= temp; i++)
        {
            if (temp % i == 0) cnt1++;
        }
        if (cnt1 == 2) cnt2++;

    } while (next_permutation(ind.begin(), ind.end()));

    ind.clear();

    for (int i = 0; i < 2; i++) {
        ind.push_back(1);
    }
    for (int i = 0; i < n.size() - 2; i++) {
        ind.push_back(0);
    }
    sort(ind.begin(), ind.end());

    do 
    {
        t.clear();
        cnt1 = 0;

        for (int i = 0; i < ind.size(); i++) 
        {
            if (ind[i] == 1) 
            {
                t += n[i];
            }
        }
        if (t[0] == '0') continue;
        temp = atoi(t.c_str());

        for (int i = 1; i <= temp; i++)
        {
            if (temp % i == 0) cnt1++;
        }
        if (cnt1 == 2) cnt2++;

    } while (next_permutation(ind.begin(), ind.end()));

    /*ind.clear();

    for (int i = 0; i < 3; i++) {
        ind.push_back(1);
    }
    for (int i = 0; i < n.size() - 3; i++) {
        ind.push_back(0);
    }
    sort(ind.begin(), ind.end());*/

    do
    {
        t.clear();
        cnt1 = 0;

        for (int i = 0; i < ind.size(); i++)
        {
            if (ind[i] == 1)
            {
                t += n[i];
            }
        }
        if (t[0] == '0') continue;
        temp = atoi(t.c_str());

        for (int i = 1; i <= temp; i++)
        {
            if (temp % i == 0) cnt1++;
        }
        if (cnt1 == 2) cnt2++;

    } while (next_permutation(ind.begin(), ind.end()));


    /*do
    {
        t.clear();
        cnt1 = 0;

        for (int i = 0; i < n.size(); i++)
        {
            t += n[i];
        }
        if (t[0] == '0') continue;
        temp = atoi(t.c_str());

        for (int i = 1; i <= temp; i++)
        {
            if (temp % i == 0) cnt1++;
        }
        if (cnt1 == 2) cnt2++;

    } while (next_permutation(n.begin(), n.end()));*/

    cout << cnt2;

    return 0;
}