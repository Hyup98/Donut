#include <math.h>
#include <iostream>
#include <Windows.h>
#include "Point.h"
using namespace std;

void gotoxy(int x, int y)
{

	COORD pos = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

int main(void)
{
	const double PI = 3.1415926;

	char const pix[12] = { '.', ',', '-', '~', ':', ';', '=', '!', '*', '#', '$', '@' };
	const int distanceToScreen = 5;
	const int distanceToObject = 10;
	const int radiusToAxis = 20;
	const int radius = 5;
	int size = 0;
	//Screen point = { distanceToScreen * x / distanceToObject ,
	//                    distanceToScreen * x / distanceToObject)

	//z-buffer
	//store z

	//{x, y, z} -> (x,y,z)=(R2,0,0)+(R1cosθ,R1sinθ,0) ->  let’s call it θ — from 0 to 2π
	//((R2+R1cosθ)cosϕ,R1sinθ,−(R2+R1cosθ)sinϕ) -> ->  let’s call it ϕ — from 0 to 2π
	float x;
	float temX;
	float temY;
	float y;
	float z;
	float zBuffer[500][500];
	for (size_t i = 0; i < 100; i++)
	{
		for (size_t j = 0; j < 100; j++)
		{
			zBuffer[i][j] = 0;
		}
	}

	int index;
	float L;
	float tem;

	Point points[(int)(4 * 3.1415926 * radiusToAxis * radius + 1)];
	while (true)
	{
		for (float j = 0; j < 2 * PI; j += 0.02)
		{
			for (float i = 0; i < 2 * PI; i += 0.02)//y축 회전
			{
				for (double k = 0; k < 2 * PI; k += 0.02) //원 만들기
				{
					x = (radiusToAxis + radius * cos(k)) * (cos(j) * cos(i) + sin(j) * sin(j) * sin(i)) - radius * cos(j) * sin(j) * sin(k);
					y = (radiusToAxis + radius * cos(k)) * (cos(i) * sin(j) - cos(j) * sin(j) * sin(i)) + radius * cos(j) * cos(j) * sin(k);
					z = cos(j) * (radiusToAxis + radius * cos(k)) * sin(i) + radius * sin(j) * sin(k);
					L = cos(i) * cos(k) * sin(j) - cos(j) * cos(k) * sin(i) - sin(j) * sin(k) + cos(j) * (cos(j) * sin(k) - cos(k) * sin(j) * sin(i));
					tem = 1 / z;
					temX = x * distanceToScreen / distanceToObject;
					temY = y * distanceToScreen / distanceToObject;
					if (zBuffer[(int)temX + 100][(int)temY + 100] < tem)
					{
						zBuffer[(int)temX + 100][(int)temY + 100] = tem;
						index = (int)(L * 8);
						if (index < 0) {
							index = 0;
						}
						if (index > 11)
						{
							index = 11;
						}
						gotoxy(temX + 50, temY + 50);
						printf("%c", pix[index]);
					}
				}
			}
			for (size_t i = 0; i < 500; i++)
			{
				for (size_t j = 0; j < 500; j++)
				{
					zBuffer[i][j] = 0;
				}
			}
			Sleep(100);
			std::system("cls");
		}

	}
	return 0;
}

