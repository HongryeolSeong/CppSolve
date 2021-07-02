#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int nx, ny;
	vector<int> x;
	vector<int> y;
	int flx = 0;
	int fly = 0;
	int rx, ry;

	for (int i = 0; i < 3; i++)
	{
		cin >> nx >> ny;
		x.push_back(nx);
		y.push_back(ny);
	}

	for (int i = 0; i < 3; i++)
	{
		if (x[0] == x[i])
		{
			flx++;
		}
	}

	if (flx == 1) 
	{ 
		rx = x[0]; 
	}
	else if (flx == 2)
	{
		for (int i = 0; i < 3; i++)
		{
			if (x[0] != x[i])
			{
				rx = x[i];
			}
		}
	}

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

	cout << rx << " " << ry;

	return 0;
}