#include "Quaternion.h"
#include "Mathf.h"

using namespace eEngine::Maths;

Quaternion* Quaternion::identity = new Quaternion(1,0,0,0);

Quaternion::Quaternion(float w, float x, float y, float z)
{
    this->w = w;
    this->x = x;
    this->y = y;
    this->z = z;
}

Quaternion::Quaternion()
{

}

bool Quaternion::operator==(const Quaternion& other)
{
	if(this->w == other.w && this->x == other.x && this->y == other.y && this->z == other.z)
		return true;
	else
		return false;
}

Quaternion Quaternion::operator*(const Quaternion& other)
{
	float newX = this->w * other.x + this->x * other.w + this->y * other.z - this->z * other.y;
	float newY = this->w * other.y + this->y * other.w + this->z * other.x - this->x * other.z;
	float newZ = this->w * other.z + this->z * other.w + this->x * other.y - this->y * other.x;
	float newW = this->w * other.w - this->x * other.x - this->y * other.y - this->z * other.z;

    Quaternion temp;
	temp.w = newW;
	temp.x = newX;
	temp.y = newY;
	temp.z = newZ;
    temp.normalize();
    return temp;
}

Vector3 Quaternion::operator*(const Vector3& other)
{
	float num = this->x * 2;
	float num2 = this->y * 2;
	float num3 = this->z * 2;
    float num4 = this->x * num;
	float num5 = this->y * num2;
	float num6 = this->z * num3;
	float num7 = this->x * num2;
	float num8 = this->x * num3;
	float num9 = this->y * num3;
	float num10 = this->w * num;
	float num11 = this->w * num2;
	float num12 = this->w * num3;

	Vector3 temp;
	temp.x = (1 - (num5 + num6)) * other.x + (num7 - num12) * other.y + (num8 + num11) * other.z;
	temp.y = (num7 + num12) * other.x + (1 - (num4 + num6)) * other.y + (num9 - num10) * other.z;
	temp.z = (num8 - num11) * other.x + (num9 + num10) * other.y + (1 - (num4 + num5)) * other.z;
    return temp;
}

Quaternion Quaternion::AngleAxis(float angle, Vector3 axis)
{
    angle *= Mathf::DegToRad;
    float w = Mathf::Cos(angle / 2);
    float x = axis.x * Mathf::Sin(angle / 2);
	float y = axis.y * Mathf::Sin(angle / 2);
	float z = axis.z * Mathf::Sin(angle / 2);
    Quaternion temp;
	temp.w = w;
	temp.x = x;
	temp.y = y;
	temp.z = z;
    return temp;
}

Vector3 Quaternion::QuaternionToEuler(Quaternion q)
{
    int pole;
	float x;
	float y;
	float z;
	
	if(q.w * q.x * q.y * q.z > 0.499f)
		pole = 1;
	else if(q.w * q.x * q.y * q.z < -0.499f)
		pole = -1;
	else
		pole = 0;
		
	if(pole == 0)
	{
		x = Mathf::Atan2(2 * (q.y * q.w + q.x * q.z), 1 - 2 * (q.y * q.y + q.x * q.x)) * Mathf::RadToDeg;
		y = Mathf::Asin(Mathf::Clamp(2 * (q.w * q.x - q.z * q.y), -1, 1)) * Mathf::RadToDeg;
		z = Mathf::Atan2(2 * (q.w * q.z + q.y * q.x), 1 - 2 * (q.x * q.x + q.z * q.z)) * Mathf::RadToDeg;			
	}
	else
	{
		x = 0;
		y = pole * Mathf::PI * 0.5f * Mathf::RadToDeg;
		z = pole * 2 * Mathf::Atan2(q.y, q.w) * Mathf::RadToDeg;
	}
	Vector3 temp;
	temp.x = x;
	temp.y = y;
	temp.z = z;
    return temp;
}

Quaternion Quaternion::EulerToQuaternion(Vector3 vector)
{
    float hr = vector.z * 0.5f;
	float shr = Mathf::Sin(hr);
	float chr = Mathf::Cos(hr);
	float hp = vector.y * 0.5f;
	float shp = Mathf::Sin(hp);
	float chp = Mathf::Cos(hp);
	float hy = vector.x * 0.5f;
	float shy = Mathf::Sin(hy);
	float chy = Mathf::Cos(hy);
	float chy_shp = chy * shp;
	float shy_chp = shy * chp;
	float chy_chp = chy * chp;
	float shy_shp = shy * shp;

    Quaternion temp;
	temp.w = (chy_chp * chr) + (shy_shp * shr);
	temp.x = (shy_chp * chr) - (chy_shp * shr);
	temp.y = (chy_shp * chr) + (shy_chp * shr);
	temp.z = (chy_chp * shr) - (shy_shp * chr);
    return temp;
}

Quaternion Quaternion::Slerp(Quaternion start, Quaternion end, float factor)
{
    float d = start.x * end.x + start.y * end.y + start.z * end.z + start.w * end.w;
	float absDot = d < 0.f ? -d : d;

	float scale0 = 1 - factor;
	float scale1 = factor;

	if ((1 - absDot) > 0.1f) 
	{
		float angle = (float)Mathf::Acos(absDot);
		float invSinTheta = 1 / Mathf::Sin(angle);
		scale0 = (Mathf::Sin((1 - factor) * angle) * invSinTheta);
		scale1 = (Mathf::Sin((factor * angle)) * invSinTheta);
	}
	if (d < 0.f) 
		scale1 = -scale1;
		
	Quaternion interpolated;
	interpolated.w = (scale0 * start.w) + (scale1 * end.w);
	interpolated.x = (scale0 * start.x) + (scale1 * end.x);
	interpolated.y = (scale0 * start.y) + (scale1 * end.y);
	interpolated.z = (scale0 * start.z) + (scale1 * end.z);
	return interpolated;
}

Quaternion Quaternion::Normalize(Quaternion q)
{
    float lenght;
	Quaternion newQuaternion;
	lenght = Mathf::Sqrt(q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z);

	newQuaternion.w = q.w;
	newQuaternion.x = q.x;
	newQuaternion.y = q.y;
	newQuaternion.z = q.z;

	if(lenght == 1)
		return newQuaternion;
	else
	{
		newQuaternion.w /= lenght;
		newQuaternion.x /= lenght;
		newQuaternion.y /= lenght;
		newQuaternion.z /= lenght;
	}
	return newQuaternion;
}

void Quaternion::normalize()
{
   	float lenght = Mathf::Sqrt(w*w + x*x + y*y + z*z);
	this->w /= lenght;
	this->x /= lenght;
	this->y /= lenght;
	this->z /= lenght;
}