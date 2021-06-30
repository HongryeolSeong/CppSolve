#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	long A, B, C;			// A(
	long long ans;

	cin >> A >> B >> C;

	if (B >= C)
	{
		ans = -1;
	}
	else
	{
		ans = (A / (C - B)) + 1;
	}

	cout << ans;

	return 0;
}