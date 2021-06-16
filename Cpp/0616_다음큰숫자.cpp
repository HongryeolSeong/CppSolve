#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n = 15;         // ���� ����
    int cn = n;         // n �ӽ� ����� ����
    vector<int> bn1;    // n�� 2���� ����
    vector<int> bn2;    // n ���� ������ 2���� ����
    int cnt = 0;        // bn1�� 1�� ����
    int cnt2 = 0;       // bn2�� 1�� ����

    // 1. n�� 2��ȭ
    while (1)
    {
        bn1.push_back(n % 2);
        n /= 2;
        if (n == 0) break;
    }

    // 2. bn1�� 1�� ���� ī��Ʈ
    for (int i = 0; i < bn1.size(); i++)
    {
        if (bn1[i] == 1)
        {
            cnt++;
        }
    }

    // 3. n ������ �� �������� 2��ȭ �� 1�� ���� ī��Ʈ
    n = cn;             // 1�� �������� 2��ȭ�� �ϸ� n�� 0�� �Ǿ����Ƿ�
                        // �ٽ� ���� ������ �ʱ�ȭ

    while (1)           // ���ϴ� ���� ã�������� �ݺ�
    {
        n++;            // n�� ������ ������ �ʱ�ȭ
        cn = n;         // ������ n�� �ӽ� ���� cn�� ����(2��ȭ�� ���� ������ cn)
        cnt2 = 0;       // 1�� ���� �ʱ�ȭ
        bn2.clear();    // bn2 ���͸� 0���� �ʱ�ȭ

        while (1)       // ������ n�� 2��ȭ
        {
            bn2.push_back(cn % 2);
            cn /= 2;
            if (cn == 0) break;
        }

        for (int i = 0; i < bn2.size(); i++)    // bn2�� 1�� ���� ī��Ʈ
        {
            if (bn2[i] == 1)
            {
                cnt2++;
            }
        }
        
        if (cnt == cnt2) break;                 // bn1 1�� ������ bn2 1�� ������ �������
                                                // �ݺ��� Ż�� �� ���ϴ� n���� ��Եȴ�.
    }

    return 0;
}