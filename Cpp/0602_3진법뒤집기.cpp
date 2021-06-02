#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int ary[1000];		// n�� 3������ ���� �迭
	int index = 0;		// ary�� ������ �ε���(3���� �� �ڸ���)
	int res = 0;		// ���� ��ȯ ����
	int i;

	// 1. n�� 3������ ��ȯ. n -> ary
	while (1)
	{
		ary[index] = n % 3;	// ary[0]�� �������� 3���� ù �ڸ����� ���� ����
		n /= 3;				// ���� ������
		if (n == 0) break;	// �������� 0�̸�(3���� ��ȯ �Ϸ�) �ݺ��� Ż��
		index++;			// 3���� ��ȯ���� +1
	}

	// 2. n(3)�� �� �� ����. ary �� �� ����
	int temp;		// swap�� ���� �ӽ� ����
	int j = index;	// ary�� ������ �ε���
	for (i = 0; i <= index / 2; i++)	// �յ� ������ ���� ó������ �迭�� �߰����� ����
	{
		//swap
		temp = ary[i];
		ary[i] = ary[j];
		ary[j] = temp;
		j--;
	}
	
	// 3. ������ n(3)�� 10������ ��ȯ. ary -> res
	int three = 1;					// 3���� ��ȯ�� 3�� �ŵ������� ���� ����
	for (i = 0; i <= index; i++)
	{
		res += ary[i] * three;		// 3���� ��ȯ
		three *= 3;					// ���� �ŵ����� �����
	}
	
	return res;
}

int main()
{
	int res = 0;

	res = solution(125);
	cout << res;
}