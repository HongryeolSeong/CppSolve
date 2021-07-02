#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int T;
	vector<int> vx1;
	int x1;
	vector<int> vx2;
	int x2;
	vector<int> vy1;
	int y1;
	vector<int> vy2;
	int y2;
	vector<int> vr1;
	int r1;
	vector<int> vr2;
	int r2;
	int idx = 0;
	int cnt = 0;
	vector<int> vcnt;

	cin >> T;
	
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

	if (x1 == x2 && r1 == r2 && y1 == y2)
	{
		cnt = -1;
		vcnt.push_back(cnt);
	}
	else
	{
		while (1)
		{
			for (int i = vx1[idx] - vr1[idx]; i <= vy1[idx] + vr1[idx]; i++)
			{
				for (int j = vx1[idx] - vr1[idx]; j <= vy1[idx] + vr1[idx]; j++)
				{
					if (pow(i - vx1[idx], 2) + pow(j - vy1[idx], 2) == pow(vr1[idx], 2) &&
						pow(i - vx2[idx], 2) + pow(j - vy2[idx], 2) == pow(vr2[idx], 2))
					{
						cnt++;
					}
				}
			}
			idx++;
			vcnt.push_back(cnt);
			cnt = 0;
			if (idx == T) break;
		}
	}

	for (int i = 0; i < vcnt.size(); i++)
	{
		cout << vcnt[i] << '\n';
	}

	return 0;
}