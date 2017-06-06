#include "Mathf.h"
#include <math.h>

using namespace eEngine::Maths;

const float Mathf::PI = 3.14159265358979323846f;
const float Mathf::DegToRad = (PI * 2) / 360;
const float Mathf::RadToDeg = 360 / (PI * 2);

float Mathf::Lerp(float start,float end, float factor)
{
	return (1.0f - factor) * start + factor * end;
}

float Mathf::Cos(float radian)
{
	return cos(radian);
}

float Mathf::Sin(float radian)
{
	return sin(radian);
}

float Mathf::Tan(float radian)
{
	return tan(radian);
}

float Mathf::Atan2(float y, float x)
{
	return atan2(y,x);
}

float Mathf::Asin(float radian)
{
	return asin(radian);
}

float Mathf::Acos(float radian)
{
	return acos(radian);
}

float Mathf::Clamp(float value, float minimum, float maximum)
{
	return Mathf::Min(maximum, Mathf::Max(value, minimum));
}

float Mathf::Min(float a, float b)
{
	if(a < b)
		return a;
	else
		return b;
}

float Mathf::Max(float a, float b)
{
	if(a > b)
		return a;
	else
		return b;
}

float Mathf::Sqrt(float value)
{
	return sqrt(value);
}