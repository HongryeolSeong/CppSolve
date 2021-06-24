#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    string skill = "CBD";       // ������ �� skill ��Ʈ��
    vector<string> skill_trees = { "BACDE", "CBADF", "AECB", "BDA" };   // �˻� ���� ��ųƮ�� ����<��Ʈ��>
    string t;                   // ��ųƮ���� ��Ҹ� ��� ���� �ӽ� ��Ʈ��
    int flag;                   // t�� skill�� �ٸ����� ���� �Ǵ��� ���� flag
    int answer = 0;             // skill ������ �ؼ��ϴ� ��ųƮ���� ��

    // 1. skill�� ���ϱ�����
    //    ��ųƮ���� ��Ʈ������ skill�� ��ҿ� ���� �͵��� ��� t�� ����
    for (int i = 0; i < skill_trees.size(); i++)
    {
        // ��ųƮ���� ���� ��Ʈ������ �Ѿ���� �׻� �ʱ�ȭ
        flag = 0;
        t.clear();

        // ��ųƮ������ skill�� ���� ��Ҹ� t�� ��´�
        for (int j = 0; j < skill_trees[i].size(); j++)
        {
            for (int k = 0; k < skill.size(); k++)
            {
                if (skill_trees[i][j] == skill[k])
                {
                    t.push_back(skill_trees[i][j]);
                }
            }
        }

        // 2. �ϼ��� t�� skill�� ���Ѵ�.
        for (int l = 0; l < t.size(); l++)
        {
            if (t[l] != skill[l])   // ���� �ϳ��� �ٸ��ٸ�
            {
                flag = 1;           // flag�� 1�� �ٲ��
                break;              // �� �ݺ����� Ż���Ѵ�.
            }
        }

        // 3. ���� t�� skill�� ������ �ؼ��ϴ� ��Ʈ���̶��
        if (flag == 0)
        {
            answer++;   // �����ϴ� ��ųƮ���� ���� ������Ų��.
        }
    }

    cout << answer;

    return 0;
}