#include <string>
#include <iostream>
using namespace std;

int main()
{
    string dirs = "LLLLLLR";    // �湮���� ��θ� ���� ���ڿ�
    int mx[600] = { 0 };        // �湮���� x��θ� ���� ���� �迭(�� ��� 0���� �ʱ�ȭ)
    int my[600] = { 0 };        // �湮���� y��θ� ���� ���� �迭(�� ��� 0���� �ʱ�ȭ)
    int cntx = 0;               // mx�� ������
    int cnty = 0;               // my�� ������
    int ix = 0;                 // mx�� �ε���
    int iy = 0;                 // my�� �ε���
    int ry, rx;                 // ��ǥ�� ���� ���� ��� ��
    int res1 = 0;               // �ߺ��� ��� ���� ������ mx�� ������(= ���� x���� ��� ��)
    int res2 = 0;               // �ߺ��� ��� ���� ������ my�� ������(= ���� y���� ��� ��)
    int res;                    // res1 + res2
    //int a[11][11] = { 0 };    // �ϴٺ��� ��ǥ ���� �ʿ�� ���� ��
    int x = 5;                  // ó�� x��ǥ
    int y = 5;                  // ó�� y��ǥ

//                     x��
//       0  1  2  3  4  5  6  7  8  9  10
//     0
//     1
//     2            (y, x)�� �����ϰ� �߽��ϴ�. 
//     3            ������ (x, y)������ �ϴٺ��ϱ� �̷��� �ع���
//     4
// y�� 5             (5, 5) -> ����
//     6
//     7
//     8
//     9
//     10

    // 1. dirs�� �о� ���⿡ ���� ��� �� ���Ѵ�
    for (int i = 0; i < dirs.size(); i++)
    {
        if (dirs[i] == 'U') // up
        {
            y--;            // ���� �� ĭ �ö󰡹Ƿ� y--

            if (y < 0)      // U�� ���� ���� ��ǥ�� ��� ���� ���
            {
                y = 0;      // U�� ������ �ٸ� �������� �������� 0���� �ʱ�ȭ
                continue;
            }

            ry = (y + (y + 1)) + (x * 100); // ��ι迭�� ���� ��� �� ���
                                            // (5, 5) -> (4, 5)�� ���
                                            // ry = 509�� �ȴ�.
            cnty++;                         // ��� �迭�� ������ ����
            my[iy++] = ry;                  // ��� �迭�� ����
        }
        else if (dirs[i] == 'D') // down
        {
            y++;
            if (y > 10)
            {
                y = 10;
                continue;
            }
            ry = (y + (y - 1)) + (x * 100);
            cnty++;
            my[iy++] = ry;
        }
        else if (dirs[i] == 'L') // left
        {
            x--;
            if (x < 0)
            {
                x = 0;
                continue;
            }
            rx = (x + (x + 1)) + (y * 100);
            cntx++;
            mx[ix++] = rx;
        }
        else if (dirs[i] == 'R') // right
        {
            x++;
            if (x > 10)
            {
                x = 10;
                continue;
            }
            rx = (x + (x - 1)) + (y * 100);
            cntx++;
            mx[ix++] = rx;
        }
    }

    // 2. �湮�� ������ �� ��� �迭���� �ߺ��Ǵ� ��ο� ���� ó��
    for (int i = 0; i < cntx; i++)      // mx�迭 ó��
    {
        for (int j = 0; j < cntx; j++)
        {
            if (i == j) continue;
            if (mx[i] == mx[j])         // �ߺ��Ǵ� �� ���� �� �߽߰�
            {
                mx[j] = -1;             // �� �� �ϳ��� -1�� ó��
            }
        }
    }

    for (int i = 0; i < cnty; i++)      // my�迭 ó��
    {
        for (int j = 0; j < cnty; j++)
        {
            if (i == j) continue;
            if (my[i] == my[j])
            {
                my[j] = -1;
            }
        }
    }

    // 3. �������� ó�� ���� ���� ���̸� ���Ѵ�
    for (int i = 0; i < cntx; i++)
    {
        if (mx[i] == -1) continue;  // 2�ܰ迡�� ó���� �ߺ� ���� ����
        res1++;                     // ī��Ʈ �Ѵ�
    }

    for (int i = 0; i < cnty; i++)
    {
        if (my[i] == -1) continue;
        res2++;
    }

    res = res1 + res2;              // ī���� x��μ��� y��� ���� ���Ͽ� ������ ���

    cout << res;

    return 0;
}