#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int bridge_length = 5;                                      // �ٸ��� ����(1�� �� �뾿 �ְ�, 1�ʿ� 1�� ������)
    int weight = 5;                                             // �ٸ��� ��ƿ �� �ִ� ����
    vector<int> truck_weights = { 2, 2, 2, 2, 1, 1, 1, 1, 1 };  // �ٸ� �ǳʷ��� ��� ���� Ʈ������ ����(��� ��ҷ� �� �� �� �ִ�.)
    vector<int> on;                                             // ���� �ٸ� ���� �ִ� Ʈ����
    vector<int> out;                                            // �ٸ��� ������ ��� Ʈ����
    vector<int> time;                                           // Ʈ���� �ٸ��� ������ �ð�
    int sz = truck_weights.size();                              // �� ó�� ������̾��� Ʈ���� ����
    int sum = 0;                                                // on�� �ִ� Ʈ������ ���� �� ��
    int cnt = 1;                                                // ���� ��ȯ ���� �� �������� ��

    // ������ ���� ǥ�� ������ ������� ����ȴ�.
    while (1)
    {
        // 1. ���� on -> out���� �� Ʈ���� �ִ��� �Ǵ��Ѵ�.
        if (time.size() > 0 && time[0] == bridge_length)    // on�� Ʈ���� out���� �� �ð��� �ƴ��� Ȯ��
        {                                                   // ex) �ٸ� ���� = 2, time = { 2, ... }�϶�
                                                            //     on�� ù��° Ʈ���� out���� ����.
            out.push_back(on[0]);
            on.erase(on.begin());
            time.erase(time.begin());                       // out���� �� Ʈ���� time�� �����Ѵ�.
        }

        // 2. ��� ��� -> on���� �� Ʈ���� �ִ��� �Ǵ��Ѵ�.
        // 2-1. ���� on�� �ִ� Ʈ������ ���Ը� ���Ѵ�(= sum).
        sum = 0;
        for (int i = 0; i < on.size(); i++)
        {
            sum += on[i];
        }

        // 2-2. ���� sum�� on���� �ǳʰ� Ʈ���� ���Ը� ���Ѵ�.
        if (truck_weights.size() > 0)
        {
            sum += truck_weights[0];
        }

        // 2-3. �׷��� ���� sum�� weight���� �۰�, ���� on�� Ʈ�� ���� �ٸ� ���̺��� ���� ���
        // ��� ��ҿ��� on���� Ʈ�� �� �� �ѱ��.
        if (sum <= weight && on.size() < bridge_length)
        {
            if (truck_weights.size() > 0)
            {
                on.push_back(truck_weights[0]);             // on�� �� �� �ѱ��
                truck_weights.erase(truck_weights.begin()); // �ش� Ʈ���� ��� ��ҿ��� �����.
            }

            time.push_back(0);                              // on�� �����Ƿ� �ش� Ʈ���� time�� �����.
            for (int i = 0; i < time.size(); i++)           // �ð��� 1�� �귶���Ƿ� on�� ��� Ʈ���� �ð���
            {                                               // 1�ʾ� �����ش�.
                time[i]++;
            }
        }
        else                                                // ���� �ش� ������ �ƴ� ��쿡��
        {                                                   // �׷��� �ð��� 1�� �귶����
            for (int i = 0; i < time.size(); i++)           // onƮ������ �ð��� 1�� ���� ��Ų��.
            {
                time[i]++;
            }
        }

        // 3. 1�� 2������ ���� out�� ��� Ʈ���� ������ ���
        if (out.size() == sz) break;    // �ٸ� �ǳʱ� ����

        cnt++;                          // �� ���������� ������ ��� ��ü ���� �ð� 1�� �÷����Ѵ�.
                                        // �ٸ� �ǳʱ� ��������� cnt�� ���� �ɸ� �ð�
    }

        // ������ ������ -> on -> out������ ���μ����� ����ž� ������
        // �׷��� �ڵ带 ¥�� ������ ǥ��� ������ �ȵż�
        // on -> out�� ���� ��Ų���� ������ -> on�� �����ߴ�.
        // ó�� on -> out �������� �� ó���� ��Ȳ�� �����ϰ� �ݺ����� ������ ����̶�
        // ��ü������ ���� ������ -> on -> out������ ����ȴٰ� �� �� �ִ�.
        
    cout << cnt;

    return 0;
}