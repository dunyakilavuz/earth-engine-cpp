#include "Vector4.h"

using namespace eEngine::Maths;

Vector4* Vector4::one = new Vector4(1,1,1,1);
Vector4* Vector4::zero = new Vector4(0,0,0,0);

Vector4::Vector4(float x,float y,float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Vector4::Vector4()
{

}

Vector4 Vector4::operator+(const Vector4& other)
{
	Vector4 temp;
	temp.x = this->x + other.x;
	temp.y = this->y + other.y;
	temp.z = this->z + other.z;
	temp.w = this->w + other.w;
	return temp;
}

Vector4 Vector4::operator-(const Vector4& other)
{
	Vector4 temp;
	temp.x = this->x - other.x;
	temp.y = this->y - other.y;
	temp.z = this->z - other.z;
	temp.w = this->w - other.w;
	return temp;
}

Vector4 Vector4::operator*(const Vector4& other)
{
	Vector4 temp;
	temp.x = this->x * other.x;
	temp.y = this->y * other.y;
	temp.z = this->z * other.z;
	temp.w = this->w * other.w;
	return temp;
}

std::string Vector4::toString()
{
	std::stringstream temp;
	temp << "(" << this->x << "," << this->y << "," << this->z << ","  << this->w <<")";
	return temp.str();
}