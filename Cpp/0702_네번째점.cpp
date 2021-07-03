#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int nx, ny;		// 입력받을 x, y 좌표
	vector<int> x;		// nx를 담을 벡터
	vector<int> y;		// ny를 담을 벡터
	int flx = 0;		// x좌표에 대한 플래그
	int fly = 0;		// y좌표에 대한 플래그
	int rx, ry;		// 주어진 사각형의 네번째 점의 좌표


	// 1. 직사각형의 세 점의 좌표를 입력 받는다.
	for (int i = 0; i < 3; i++)
	{
		cin >> nx >> ny;
		x.push_back(nx);
		y.push_back(ny);
	}

	// 2. 주어진 x, y 벡터로 네번째 점을 구해야 하는데,
	//    축에 평행한 직사각형의 좌표는 한 규칙이 있다.
	//    점의 x 좌표는 2개의 숫자가 각각 2개씩 있는 벡터로 이루어지고,
	//	  점의 y 좌표 역시 동일하게 구성 된다.
	// ex) x : 5, 5, 7 이면 네번째 점의 x는 7이 되고,
	//     y : 1, 2, 1 이면 네번째 점의 y는 2가 된다.

	// 2-1. 사각형 첫번째 점을 기준으로
	//      해당 x가 벡터에 몇 개 있는지 판단한다.
	for (int i = 0; i < 3; i++)
	{
		if (x[0] == x[i])
		{
			flx++;
		}
	}
	// 만약 첫번째 x가 1개밖에 없다면
	if (flx == 1) 
	{ 
		rx = x[0];			// 위의 규칙대로 네번째 점의 x는 첫번째 x가 되고,
	}
	// 첫번째 x가 2개라면
	else if (flx == 2)
	{
		for (int i = 0; i < 3; i++)	// 벡터에서 첫번재 x와 다른 x를 찾아(1개 밖에 없을테니)
		{
			if (x[0] != x[i])
			{
				rx = x[i];	// 네번째 점의 x로 정한다.
			}
		}
	}
	// 2-2. y역시 동일한 방법으로 정한다.
	for (int i = 0; i < 3; i++)
	{
		if (y[0] == y[i])
		{
			fly++;
		}
	}
	if (fly == 1)
	{
		ry = y[0];
	}
	else if (fly == 2)
	{
		for (int i = 0; i < 3; i++)
		{
			if (y[0] != y[i])
			{
				ry = y[i];
			}
		}
	}

	// 3. 구하고자는 점의 x, y 출력
	cout << rx << " " << ry;

	return 0;
}
