#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int T;					// �׽�Ʈ ���̽� ��
	vector<int> vx1;		// ��ǥ1�� x��ǥ
	vector<int> vy1;		// ��ǥ1�� y��ǥ
	vector<int> vr1;		// ��ǥ1�� Ÿ�ٰ� �Ÿ�
	vector<int> vx2;		// ��ǥ2�� x��ǥ
	vector<int> vy2;		// ��ǥ2�� y��ǥ
	vector<int> vr2;		// ��ǥ2�� Ÿ�ϰ� �Ÿ�

	int x1;					// ����� �Է� ���� ������
	int y1;
	int r1;
	int x2;
	int y2;
	int r2;					// ������

	int idx = 0;			// �ݺ����� ���� ���� �ε���
	vector<int> vcnt;		// ���� ��ȯ�� Ÿ�� ��ǥ ��


	// Ÿ�� ��ǥ��
	// ����:��ǥ1, ������:r1�� ��1�� -> ��ǥ1���� ���簡���� Ÿ���� ����
	// ����:��ǥ2, ������:r2�� ��2�� -> ��ǥ2���� ���簡���� Ÿ���� ����
	// �����Ͽ� ��ġ�� ��츦 ã�� �� ������ ���Ѵ�.

	// 1. �׽�Ʈ�� ���̽��� ���� �Է¹޴´�.
	cin >> T;
	
	// 2. T��ŭ ���̽� �� �����͸� �Է¹޴´�.
	//    �����ʹ� �ٷ� �ش� ���Ϳ� ����.
	for (int i = 0; i < T; i++)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		vx1.push_back(x1);
		vx2.push_back(x2);
		vr1.push_back(r1);
		vy1.push_back(y1);
		vy2.push_back(y2);
		vr2.push_back(r2);
	}

	// 3. �ϼ��� ���͵�� Ÿ�� ��ǥ���� ���� ���Ѵ�.
	while (1)
	{
		// 3-1. ��ǥ1�� ��ǥ2�� �����Ͱ� ��� ���� ���
		//      Ÿ�� ��ǥ ���� ���Ѵ� �̹Ƿ� cnt�� -1�� �ȴ�.
		if (vx1[idx] == vx2[idx] && vr1[idx] == vr2[idx] && vy1[idx] == vy2[idx])
		{
			vcnt.push_back(-1);
		}
		else 
		{
			// 3-2. �� ���� ������ �Ÿ���
			//      �� �������� ���� �Ÿ��� ���� ���(����) �̰ų�
			//      �� �������� �� �Ÿ��� ���� ���(����) �̸� ��ǥ ���� 1��.
			if (pow(vx2[idx] - vx1[idx], 2) + pow(vy2[idx] - vy1[idx], 2) == pow(vr1[idx] + vr2[idx], 2) ||
				pow(vx2[idx] - vx1[idx], 2) + pow(vy2[idx] - vy1[idx], 2) == pow(vr1[idx] - vr2[idx], 2))
			{
				vcnt.push_back(1);
			}
			// 3-3. �� ���� ������ �Ÿ���
			//      �� �������� ���� �Ÿ����� �۰�,
			//      �� �������� �� �Ÿ����� ū ���(�� ������ ����) ��ǥ ���� 2��.
			else if (pow(vx2[idx] - vx1[idx], 2) + pow(vy2[idx] - vy1[idx], 2) < pow(vr1[idx] + vr2[idx], 2) &&
				pow(vx2[idx] - vx1[idx], 2) + pow(vy2[idx] - vy1[idx], 2) > pow(vr1[idx] - vr2[idx], 2))
			{
				vcnt.push_back(2);
			}
			// 3-4. �� ���� ������ ������ �������� �ٸ����,
			//      �� ������ ������ �ٸ��� ������ ���°�� ��ǥ ���� 0��.
			else
			{
				vcnt.push_back(0);
			}

			// ȫ�� ��Ģ ����
			/*for (int i = vx1[idx] - vr1[idx]; i <= vy1[idx] + vr1[idx]; i++)
			{
				for (int j = vx1[idx] - vr1[idx]; j <= vy1[idx] + vr1[idx]; j++)
				{
					if (pow(i - vx1[idx], 2) + pow(j - vy1[idx], 2) == pow(vr1[idx], 2) &&
						pow(i - vx2[idx], 2) + pow(j - vy2[idx], 2) == pow(vr2[idx], 2))
					{
						cnt++;
					}
				}
			}*/
		}

		idx++;
		if (idx == T) break;
	}

	// 4. 3���� ���� ��ǥ �� ���͸� �ϳ��� ����Ѵ�.
	for (int i = 0; i < vcnt.size(); i++)
	{
		cout << vcnt[i] << '\n';
	}

	return 0;
}