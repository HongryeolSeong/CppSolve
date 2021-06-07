#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> a = { 1, 2, 3 };                // ���� ����
    vector<bool> s = { false, false, true };    // ��ȣ ����(bool��)
    vector<int> is;                             // ��ȣ ����(int��)
    int i;                                      // �ݺ�����
    int res = 0;                                // ���� ��ȯ ����

    // 1. s������ bool ���� �̿��Ͽ� is������ ������(1 or -1) ����
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == true)       // s���Ͱ� true�� ��� is�� 1
        {
            is.push_back(1);
        }
        else if (s[i] == false) // s���Ͱ� false�� ��� is�� -1
        {
            is.push_back(-1);
        }
    }

    // is���� Ȯ�ο�
    for (i = 0; i < is.size(); i++)
    {
        cout << is[i] << " ";
    }

    cout << endl;

    // 2. is������ 1(or -1)���� �̿��Ͽ� ��ȣ�� �ִ� ������ ��ȯ
    for (i = 0; i < a.size(); i++)
    {
        a[i] *= is[i];
    }

    // a���� Ȯ�ο�
    for (i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    // 3. res�� a������ ������ ���Ͽ� ���� ��ȯ�� �����
    for (i = 0; i < a.size(); i++)
    {
        res += a[i];
    }

    // res Ȯ�ο�
    cout << res;

    return 0;
}