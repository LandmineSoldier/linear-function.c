#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

int main(void)
{
	char pos[8][8] = { 0, };
	float x, y;
	float a, b, result;
	float i, j;
	int trans;
	int move;
	float fx, fy;

	scanf_s("%f %f", &fx, &fy);
	scanf_s("%f %f", &x, &y);

	b = fy;

	while (1)
	{
		// y > x
		// y < x
		// x + y < fy (y 기준 감식)
		// x + y >= fy (x 기준 증식)

		if (x + y < fy)
		{
			for (i = fy; i >= y; i--)
			{
				a = ((y - b) / x); //a값
				result = (i - b) / a; // x값에 (y-b)/a 를 넣음

				trans = (int)(result + 0.5); // x좌표를 반올림 (정수형)

				pos[(int)i][trans] = '*'; // 그 좌표에 별 저장
			}

		}
		else if (y < x)
		{
			for (i = fx; i <= x; i++)
			{
				a = ((y - b) / x); // a값 구하기
				result = (a * i) + b; // result(y좌표) = ax + b 임

				trans = (int)(result + 0.5); // y좌표를 반올림 (정수형)

				pos[trans][(int)i] = '*'; // 그 좌표에 별 저장
			}
		}
		else if (x + y >= fy)
		{
			if (y > fy)
			{
				if (x - fx < y - fy)
				{
					for (i = y; i >= fy; i--)
					{
						a = ((y - b) / x); //a값
						result = (i - b) / a; // x값에 (y-b)/a 를 넣음

						trans = (int)(result + 0.5); // x좌표를 반올림 (정수형)

						pos[(int)i][trans] = '*'; // 그 좌표에 별 저장
					}
				}
				else if (x - fx >= y - fy)
				{
					for (i = fx; i <= x; i++)
					{
						a = ((y - b) / x); // a값 구하기
						result = (a * i) + b; // result(y좌표) = ax + b 임

						trans = (int)(result + 0.5); // y좌표를 반올림 (정수형)

						pos[trans][(int)i] = '*'; // 그 좌표에 별 저장
					}
				}
			}
			else
			{
				for (i = fx; i <= x; i++)
				{
					a = ((y - b) / x); // a값 구하기
					result = (a * i) + b; // result(y좌표) = ax + b 임

					trans = (int)(result + 0.5); // y좌표를 반올림 (정수형)

					pos[trans][(int)i] = '*'; // 그 좌표에 별 저장
				}
			}


		}



		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				printf("%2c", pos[(int)i][(int)j]);
			}
			printf("\n");
		}

		move = _getch(); // 화살표값 받음

		switch (move) // p1 무빙
		{
		case UP:
			if (y != 0)
				y--;
			break;
		case LEFT:
			if (x != 0)
				x--;
			break;
		case RIGHT:
			if (x != 7)
				x++;
			break;
		case DOWN:
			if (y != 7)
				y++;
			break;
		}

		for (i = 0; i < 8;i++)
		{
			for (j = 0; j < 8;j++)
			{
				pos[(int)i][(int)j] = 0;
			}
		}
		system("cls");
	}

}
