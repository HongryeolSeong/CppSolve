#include <string>
#include <vector>
#include <iostream>
#include <algorithm>    // next_permutation()�� ����ϱ� ���� ���

using namespace std;

int main()
{
    string n = "011";  // �׽�Ʈ�� ��Ʈ��
    string t;           // n���� �߻��ϴ� ������ ��� ���� �ӽ� ��Ʈ��
    vector<int> all;    // n���� �߻��ϴ� ��� ������ ����ȭ �Ͽ� ���� ����
    vector<int> final;  // all���� �ߺ���Ҹ� ������ ����
    int k = 0;          // ������ �ڸ���(++)
    int cnt1 = 0;       // �Ҽ� �Ǵܿ� ���� ī��Ʈ1
    int cnt2 = 0;       // �Ҽ� �Ǵܿ� ���� ī��Ʈ2
    int stage = 0;      // ��� ������ ����� �ݺ����� Ż��� ����� ����
                        // "1234"�̸� 1 ~ 4���� �����ѵ� �ݺ����� Ż���Ŵ

    sort(n.begin(), n.end()); // next_permutation�� ���������� ���� ����� ���� ���·� �迭�ϴ� �Լ��̹Ƿ� 
                              // ���� ������ ������������ ���ĵǾ� �־�� ��� ����� ��(or ����)�� ���� �� �ִ�.


    // 1. n ��Ʈ������ �߻������� ��� ������ all���Ϳ� ��´�.
    while (1)
    {
        k++;            // ���� ������ �ڸ����� ���Ѵ�.(1���� ����)

        do              // 42�࿡ ���� n��Ʈ������ ���� �� �ִ�
        {               // k�ڸ����� ������ ������ �����.

            for (int i = 0; i < k; i++) // �ڸ��� ��ŭ �ݺ��Ͽ�
            {
                t += n[i];              // �ӽ� ��Ʈ��t�� �ش� ����(����)�� ��´� 
            }

            all.push_back(atoi(t.c_str())); // �ӽ� ��Ʈ�� t�� ��� ���ڸ� "����ȭ" �Ͽ� all�� ��´�.
            t.clear();                      // ��� ���� t�� �ٽ� ����ش�.

            reverse(n.begin() + k, n.end());// �ߺ��Ǵ� ������ ���ϱ� ���� k�� ���� �ڸ� ���ڸ�
                                            // ���� ��ȯ�Ѵ�.

        } while (next_permutation(n.begin(), n.end()));

        stage++;                            // n�� �� �ڸ����� �������� �ݺ��� Ż��
        if (stage == n.size()) break;       // "1234"�� ��� stage = 0 ~ 3�� �ǰ�, 
                                            // 4�� �Ǵ� ���� �ݺ��� �����Ѵ�.
    }


    // 2-1. ��� ������ ���� all���Ϳ��� �ߺ��Ǵ� ��� ����(-1�� ó���Ѵ�).
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


    // 2-2. 2-1���� ó���� ���(-1)���� ������ ��ҵ��� final���Ϳ� ��´�.
    for (int i = 0; i < all.size(); i++)
    {
        if (all[i] == -1) continue;
        final.push_back(all[i]);
    }


    // 3. final������ ��ҵ��� �Ҽ� �Ǵ��� �Ͽ� ī��Ʈ �Ѵ�.
    for (int i = 0; i < final.size(); i++)
    {
        cnt1 = 0;
        for (int j = 1; j <= final[i]; j++)
        {
            if (final[i] % j == 0) cnt1++;
        }
        if (cnt1 == 2) cnt2++;
    }

    cout << cnt2;

    return 0;
}