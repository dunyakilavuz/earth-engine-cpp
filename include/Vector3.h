#ifndef VECTOR3_H
#define VECTOR3_H

#include <string>
#include <sstream>

namespace eEngine
{
	namespace Maths
	{
		class Vector3
		{
		public:
			float x;
			float y;
			float z;

			static Vector3* one;
			static Vector3* zero;

			static Vector3* up;
			static Vector3* down;
			static Vector3* right;
			static Vector3* left;
			static Vector3* forward;
			static Vector3* backward;

			Vector3(float x, float y, float z);
			Vector3();

			bool operator==(const Vector3& other);

			Vector3 operator+(const Vector3& other);
			Vector3 operator-(const Vector3& other);
			Vector3 operator*(const Vector3& other);
			Vector3 operator*(const float value);

			void normalize();

			static Vector3 Negate(Vector3 vector);
			static float Magnitude(Vector3 vector);
			static Vector3 Normalize(Vector3 vector);
			static Vector3 Cross(Vector3 lhs, Vector3 rhs);

			std::string toString();
		};
	}
}


#endif