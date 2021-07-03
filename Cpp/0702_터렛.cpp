#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int T;				// 테스트 케이스 수
	vector<int> vx1;		// 좌표1의 x좌표
	vector<int> vy1;		// 좌표1의 y좌표
	vector<int> vr1;		// 좌표1의 타겟과 거리
	vector<int> vx2;		// 좌표2의 x좌표
	vector<int> vy2;		// 좌표2의 y좌표
	vector<int> vr2;		// 좌표2의 타켓과 거리

	int x1;				// 사용자 입력 받을 변수들
	int y1;
	int r1;
	int x2;
	int y2;
	int r2;				// 요기까지

	int idx = 0;			// 반복문에 사용될 벡터 인덱스
	vector<int> vcnt;		// 최종 반환할 타겟 좌표 수


	// 타겟 좌표는
	// 원점:좌표1, 반지름:r1인 원1과 -> 좌표1에서 존재가능한 타겟의 집합
	// 원점:좌표2, 반지름:r2인 원2를 -> 좌표2에서 존재가능한 타겟의 집합
	// 가정하여 겹치는 경우를 찾아 그 갯수를 구한다.

	// 1. 테스트할 케이스의 수를 입력받는다.
	cin >> T;
	
	// 2. T만큼 케이스 별 데이터를 입력받는다.
	//    데이터는 바로 해당 벡터에 들어간다.
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

	// 3. 완성된 벡터들로 타겟 좌표들의 수를 구한다.
	while (1)
	{
		// 3-1. 좌표1과 좌표2의 데이터가 모두 같은 경우
		//      타겟 좌표 수는 무한대 이므로 cnt는 -1이 된다.
		if (vx1[idx] == vx2[idx] && vr1[idx] == vr2[idx] && vy1[idx] == vy2[idx])
		{
			vcnt.push_back(-1);
		}
		else 
		{
			// 3-2. 두 원의 원점간 거리와
			//      두 반지름을 더한 거리가 같은 경우(외접) 이거나
			//      두 반지름을 뺀 거리가 같은 경우(내접) 이면 좌표 수는 1개.
			if (pow(vx2[idx] - vx1[idx], 2) + pow(vy2[idx] - vy1[idx], 2) == pow(vr1[idx] + vr2[idx], 2) ||
				pow(vx2[idx] - vx1[idx], 2) + pow(vy2[idx] - vy1[idx], 2) == pow(vr1[idx] - vr2[idx], 2))
			{
				vcnt.push_back(1);
			}
			// 3-3. 두 원의 원점간 거리가
			//      두 반지름을 더한 거리보다 작고,
			//      두 반지름을 뺀 거리보다 큰 경우(두 점에서 만남) 좌표 수는 2개.
			else if (pow(vx2[idx] - vx1[idx], 2) + pow(vy2[idx] - vy1[idx], 2) < pow(vr1[idx] + vr2[idx], 2) &&
				pow(vx2[idx] - vx1[idx], 2) + pow(vy2[idx] - vy1[idx], 2) > pow(vr1[idx] - vr2[idx], 2))
			{
				vcnt.push_back(2);
			}
			// 3-4. 두 원의 원점이 같지만 반지름이 다른경우,
			//      두 원점의 원점도 다르고 접점이 없는경우 좌표 수는 0개.
			else
			{
				vcnt.push_back(0);
			}

			// 홍렬 법칙 실패
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

	// 4. 3에서 만든 좌표 수 벡터를 하나씩 출력한다.
	for (int i = 0; i < vcnt.size(); i++)
	{
		cout << vcnt[i] << '\n';
	}

	return 0;
}
