#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    string skill = "CBD";
    string t;
    int k = 0;
    vector<string> skill_trees = { "BACDE", "CBADF", "AECB", "BDA" };
    int idx = 0;
    int answer = skill_trees.size();    //-방식

    // skill_trees[0] 검사
    for (int i = 0; i < skill.size(); i++)
    {
        if ()
    }

    //ㅊ방식
    /*for (int i = 0; i < skill_trees.size(); i++)
    {
        for (int j = 0; j < skill_trees[i].size(); j++)
        {
            if (skill_trees[i][j] == skill[0])
            {
                idx = j;
            }
        }
        if (idx == 0)
        {
            answer--;
        }
    }

    for (int a = 0; a < skill_trees.size(); a++)
    {
        for (int b = 0; b < skill_trees[a].size(); b++)
        {
            if (skill_trees[a][b] == skill[1])
            {
                if (b >= idx)
                {
                    answer--;
                }
            }
        }
    }*/

    cout << answer;

    return 0;
}