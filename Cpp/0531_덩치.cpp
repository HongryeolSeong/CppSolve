#include <stdio.h>

typedef struct
{
	int weight;	// ����� ������
	int height;	// ����� Ű
	int rank;	// ����� ���
} Human;

int main()
{
	int N, i, j;
	Human ary[100];			// �ο����� ���� �迭

	scanf("%d", &N);

	// 1. N���� �ο� �Է�
	for (i = 0; i < N; i++)
	{
		scanf("%d%d", &ary[i].weight, &ary[i].height);
		ary[i].rank = 1;	// ��� �ο��� ù ��ũ�� 1
	}

	// 2. �� �ο��� ��ũ ����
	// �� �ο��� ��ü �ο� �� ��ŭ �ݺ����� �����Ͽ�
	// �ش� �ο����� ��ġ�� ū �ο��� �ִ� ���
	// ��ũ + 1 ����
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			/*if (j == i)		// �ڱ� �ڽŰ� �񱳴� ��ŵ�ϱ�����
			{					// ������ ��� ��� ����
				continue;
			}*/
			if ((ary[i].weight < ary[j].weight) && (ary[i].height < ary[j].height))
			{
				ary[i].rank++;
			}
		}
	}

	// 3. �� �ο��� ��ũ ���
	for (i = 0; i < N; i++)
	{
		printf("%d ", ary[i].rank);
	}

	return 0;
}