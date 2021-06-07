#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    //vector<int> a = { 2, 1, 3, 4, 1 };    // �Ϲ����� ���
    vector<int> a = { 0, 0, 0 };            // 0�� ���� ���
    vector<int> b;                          // a���� ��ҵ��� ���ؼ� ���� ����(�ߺ� ����)
    vector<int> c;                          // b���Ϳ��� �ߺ��Ǵ� ��ҵ��� �� ����(����)

    int i, j;                               // �ݺ�����
    int temp;                               // ���ļ� swap��

    // 1. a������ ��ҵ��� ���μ��� �ϴ� ���� ��
    //    b���Ϳ� �����Ѵ�.
    for (i = 0; i < a.size(); i++)
    {
        for (j = 0; j < a.size(); j++)
        {
            if (i == j) continue;       // i = 1, j = 1�̾
                                        // a[1] + a[1]�� ��츦 ��ŵ�Ѵ�.

            b.push_back(a[i] + a[j]);   // a = { 1, 2, 3 } �ΰ��
                                        // b = { 3, 4, 3, 5, 4, 5 }�� �ȴ�.
        }
    }

    // b���� Ȯ�ο�
    for (i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }

    cout << endl;

    // 2. b���� �� �ߺ��� ���� ������ ��ҵ��� -1�� ó���Ѵ�.
    for (i = 0; i < b.size(); i++)
    {
        for (j = 0; j < b.size(); j++)
        {
            if (i == j) continue;       // b[1]�� b[1]�� ���ϴ� ���� ��ŵ
            if (b[i] == b[j])           // b��ҵ��� ���� ���Ͽ� ���� ���
            {
                b[j] = -1;              // �� �� �ϳ��� ��Ҹ� -1�� ġȯ
                                        // [1, 0, 2, 1]�� ���
                                        // [1, 0, 2, -1]�� �ٲ��ش�
            }
        }
    }

    // 3. b���Ϳ��� -1�� ������ ��� ��ҵ��� �޾ƿ´�.
    for (i = 0; i < b.size(); i++)
    {
        if (b[i] != -1)
        {
            c.push_back(b[i]);      // b = { 1, 0, 2, -1 }�� ���
                                    // c = { 1, 0, 2 }�� �ȴ�.
        }
    }

    // 4. ���������� c������ ��ҵ��� ������������ �����Ѵ�.
    for (i = 1; i < c.size(); i++)
    {
        for (j = i; j > 0; j--)
        {
            if (c[j] < c[j - 1])
            {
                temp = c[j];
                c[j] = c[j - 1];
                c[j - 1] = temp;
            }
        }
    }

    // c���� Ȯ�ο�
    for (i = 0; i < c.size(); i++)
    {
        cout << c[i] << " ";
    }

    return 0;
}