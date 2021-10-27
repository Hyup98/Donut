#include "Point.h"

Point::Point()
{
	mX = 0;
	mY = 0;
	mZ = 0;
}

Point::Point(float x, float y, float z)
{
	mX = x;
	mY = y;
	mZ = z;
}
void Point::setter(float x, float y, float z)
{
	mX = x;
	mY = y;
	mZ = z;
}