#include <string>
#include <vector>
#include <iostream>

using namespace std;

void solution(int left, int right) {
    int answer = 0;                     // ���� ��ȯ ��� ��
    int i, j;                           // �ݺ�����
    int size;                           // ������� �迭�� ũ��
    int hm = 0;                         // ����� ����
    int a[100];                         // ������� �Ǻ��� ���ڵ��� �迭

    size = right - left;                // �Էµ� left, right���� �̿���
                                        // ������� �迭�� ũ�⸦ ���Ѵ�

    for (i = 0; i <= size; i++)         // 1. ��������� ���� ���ڵ��� �迭�� �ִ´�
    {
        a[i] = left++;
    }

    for (i = 0; i <= size; i++)         // 2. �迭 ��Һ��� 1 ~ �ش��Ҹ�ŭ �ݺ�
    {                               
        for (j = 1; j <= a[i]; j++)
        {
            if (a[i] % j == 0) hm++;    // ����� ������ howmany(�������)�� 1����
        }
        if (hm % 2 != 0) a[i] *= -1;    // howmany�� Ȧ���� ��� �ش��Ҹ� ����ȭ
        hm = 0;                         // ���� ��ҷ� �Ѿ���� hm�� 0���� �ʱ�ȭ
    }

    for (i = 0; i <= size; i++)         // 3. ��������� ���� ��ȣ�� ������ ��ҵ���
    {
        answer += a[i];                 // ���� ���� ���� ��ȯ���� �����.
    }

    for (i = 0; i <= size; i++)         // ��ȣ�� �ٲ� ��ҵ� Ȯ�ο�
    {
        cout << a[i] << " ";
    }

    cout << endl;

    cout << answer << endl;             // ���� ��ȯ�� Ȯ�ο�
}

int main()
{
    int left, right;

    cin >> left >> right;

    solution(left, right);

    return 0;
}