#include <iostream>
using namespace std;

int main()
{
	int i, j;			// �ݺ�����
	int val = 1;		// �����̿� �� ����
	int n;				// �������� ũ��
	int ary[100][100];	// ������ �迭
	int r = 0, c = -1;	// ������ �迭�� ��� ��
	int turn = 1;		// �����̿� �����ϴ� ������ �ٲ��� ����

	cin >> n;

	int ogn = n;		// ������ ��ü ����� ���� n�� ����

	// ������ ä���
	while (n > 0)
	{
		for (i = 0; i < n; i++)
		{
			c += turn;
			ary[r][c] = val++;
		}

		n--;						// �� ��(or��)�� ������ ������
									// ���� ������ ��(or��)�� �� ĭ�� �۾����Ƿ�
		if (n == 0) break;

		for (i = 0; i < n; i++)
		{
			r += turn;
			ary[r][c] = val++;
		}

		turn *= -1;					// �� ���� ��� ���� ������ ������ ���Թ����� �ٲ��ش�
	}

	// ������ ��¶�
	for (i = 0; i < ogn; i++)
	{
		for (j = 0; j < ogn; j++)
		{
			cout << ary[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}