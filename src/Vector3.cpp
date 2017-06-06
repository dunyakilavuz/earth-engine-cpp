#include "Vector3.h"
#include "Mathf.h"

using namespace eEngine::Maths;

Vector3* Vector3::one = new Vector3(1,1,1);
Vector3* Vector3::zero = new Vector3(0,0,0);

Vector3* Vector3::up = new Vector3(0,1,0);
Vector3* Vector3::down = new Vector3(0,-1,0);
Vector3* Vector3::right = new Vector3(1,0,0);
Vector3* Vector3::left = new Vector3(-1,0,0);
Vector3* Vector3::forward = new Vector3(0,0,1);
Vector3* Vector3::backward = new Vector3(0,0,-1);

Vector3::Vector3(float x,float y,float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::Vector3()
{

}

bool Vector3::operator==(const Vector3& other)
{
	if(this->x == other.x && this->y == other.y && this->z == other.z)
		return true;
	else
		return false;
}

Vector3 Vector3::operator+(const Vector3& other)
{
	Vector3 temp;
	temp.x = this->x + other.x;
	temp.y = this->y + other.y;
	temp.z = this->z + other.z;
	return temp;
}

Vector3 Vector3::operator-(const Vector3& other)
{
	Vector3 temp;
	temp.x = this->x - other.x;
	temp.y = this->y - other.y;
	temp.z = this->z - other.z;
	return temp;
}

Vector3 Vector3::operator*(const Vector3& other)
{
	Vector3 temp;
	temp.x = this->x * other.x;
	temp.y = this->y * other.y;
	temp.z = this->z * other.z;
	return temp;
}

Vector3 Vector3::operator*(const float value)
{
	Vector3 temp;
	temp.x = this->x * value;
	temp.y = this->y * value;
	temp.z = this->z * value;
	return temp;
}

void Vector3::normalize()
{
	float magnitude = Magnitude(*this);
	if(magnitude != 0)
	{
		this->x /= magnitude;
		this->y /= magnitude;
		this->z /= magnitude; 
	}
}

Vector3 Vector3::Negate(Vector3 vector)
{
	Vector3 temp;
	temp.x = -vector.x;
	temp.y = -vector.y;
	temp.z = -vector.z;
	return temp;
}

float Vector3::Magnitude(Vector3 vector)
{
	return Mathf::Sqrt((vector.x * vector.x) 
					+ (vector.y * vector.y) 
					+ (vector.z * vector.z));
}

Vector3 Vector3::Normalize(Vector3 vector)
{
	Vector3 temp;
	float magnitude = Magnitude(vector);
	temp.x = vector.x / magnitude;
	temp.y = vector.y / magnitude;
	temp.z = vector.z / magnitude;
	return temp;
}

Vector3 Vector3::Cross(Vector3 lhs, Vector3 rhs)
{
	Vector3 temp;
	temp.x = lhs.y * rhs.z - lhs.z * rhs.y;
	temp.y = lhs.z * rhs.x - lhs.x * rhs.z;
	temp.z = lhs.x * rhs.y - lhs.y * rhs.x;
	return temp;
}

std::string Vector3::toString()
{
	std::stringstream temp;
	temp << "(" << this->x << "," << this->y << "," << this->z << ")";
	return temp.str();
}