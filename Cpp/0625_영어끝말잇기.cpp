#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n = 4;                                          // �����ձ⿡ ������ �ο�
    vector<string> words = { "a", "aba", "aba", "a" };  // �˻��� �����ձ� ����<��Ʈ��>
    string t;                                           // �����ձ� �ܾ ��� ���� �ӽ� ��Ʈ��
    int idx = 0;                                        // �����ձⰡ �ߴܵ� ����
    int flag = 0;                                       // �����ձⰡ �ߴܵǾ� Ż���ڰ� �������� ��Ÿ���� �÷���
    vector<int> answer = { 0, 0 };                      // ��� ����� �ߴ� �ȵɰ�츦 ����Ͽ�
                                                        // [ 0, 0 ]�� �ʱ�ȭ �Ѵ�.

    // 1. �����ձⰡ �ߴܵǴ��� �Ǵ��Ѵ�.
    for (int i = 1; i < words.size(); i++)
    {
        t = words[i];                   // �� �ܾ ��� ��� ���´�.
        for (int j = 0; j < i; j++)     // �ش� ���� �ٷ� ������ �ݺ����� ����
        {                               // �� ���� t�ܾ�� ���� �ܾ ���Դ��� �Ǵ��Ѵ�.

            if (t == words[j])          // ������ t�ܾ�� ���� �ܾ �ִٸ�
            {                           // �ش� �ε���(i)�� �ߴ� �ε����� �����Ѵ�.
                idx = i + 1;            // ���� �ε����� 0���� �����ϹǷ�(0, 1, 2, ...) -> i
                                        // 1���� �����ϴ� ����(1, 2, 3, 4, ...)�� �ߴ� �ε���
                flag = 1;               
                break;
            }
        }

        if (flag == 1) break;

        if ((flag == 1) || (words[i].front() != words[i - 1].back()))
        {
            idx = i + 1;
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        if ((idx % n == 0) && (idx != 0))
        {
            answer[0] = n;
            answer[1] = idx / n;
        }
        else
        {
            answer[0] = idx % n;
            answer[1] = ((idx - (idx % n)) / n) + 1;
        }
    }
    
    cout << answer[0] << " " << answer[1];


    return 0;
}