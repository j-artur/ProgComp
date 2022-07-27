#include <cmath>

float norm(float x, float y)
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

float angle(float x, float y)
{
	float PI = 3.14159265359;

	float radAngle = atan2(y, x);
	float degAngle = radAngle * 180 / PI;

	return degAngle;
}