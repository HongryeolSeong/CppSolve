#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	long A, B, C;			// A(고정비용), B(가변비용), C(판매가격)
	long long ans;			// 손익분기점

	cin >> A >> B >> C;

	if (B >= C)						// 가변비용이 판매가격보다 같거나 큰 경우는
	{							// 몇 개를 생산하더라도 손익분기점이 생기지 않으므로
		ans = -1;					// 손익분기점은 -1이 된다.
	}
	else							// 위의 경우가 아니면
	{
		ans = (A / (C - B)) + 1;			// A + 생산 수*B < 생산 수*C 의 부등식을 통해
	}							// 손익분기점의 바로 전 생산 수를 구할 수 있다.
								// 해당 생산 수에서 다음 단계가 손익분기점이 되므로 +1 한다.
	cout << ans;

	return 0;
}
