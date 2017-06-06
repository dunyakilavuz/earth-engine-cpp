#include "Vector2.h"
#include "Mathf.h"

using namespace eEngine::Maths;

const Vector2* Vector2::one = new Vector2(1,1);
const Vector2* Vector2::zero = new Vector2(0,0);

const Vector2* Vector2::up = new Vector2(0,1);
const Vector2* Vector2::down = new Vector2(0,-1);
const Vector2* Vector2::right = new Vector2(1,0);
const Vector2* Vector2::left = new Vector2(-1,0);

Vector2::Vector2(float x,float y)
{
	this->x = x;
	this->y = y;
}

Vector2::Vector2()
{

}

bool Vector2::operator==(const Vector2& other)
{
	if(this->x == other.x && this->y == other.y)
		return true;
	else
		return false;
}

Vector2 Vector2::operator+(const Vector2& other)
{
	Vector2 temp;
	temp.x = this->x + other.x;
	temp.y = this->y + other.y;
	return temp;
}

Vector2 Vector2::operator-(const Vector2& other)
{
	Vector2 temp;
	temp.x = this->x - other.x;
	temp.y = this->y - other.y;
	return temp;
}

Vector2 Vector2::operator*(const Vector2& other)
{
	Vector2 temp;
	temp.x = this->x * other.x;
	temp.y = this->y * other.y;
	return temp;
}

Vector2 Vector2::Negate(Vector2 vector)
{
	Vector2 temp;
	temp.x = -vector.x;
	temp.y = -vector.y;
	return temp;
}

float Vector2::Magnitude(Vector2 vector)
{
	return Mathf::Sqrt((vector.x * vector.x) + (vector.y * vector.y));
}

Vector2 Vector2::Normalize(Vector2 vector)
{
	float magnitude = Magnitude(vector);
	Vector2 temp;
	temp.x = vector.x / magnitude;
	temp.y = vector.y / magnitude;
	return temp;
}

std::string Vector2::toString()
{
	std::stringstream temp;
	temp << "(" << this->x << "," << this->y << ")";
	return temp.str();
}