#include <string>
#include <sstream>
#ifndef VECTOR2_H
#define VECTOR2_H

namespace eEngine
{
	namespace Maths
	{
		class Vector2
		{
		public:
			float x;
			float y;

			static const Vector2* one;
			static const Vector2* zero;

			static const Vector2* up;
			static const Vector2* down;
			static const Vector2* right;
			static const Vector2* left;

			Vector2(float x, float y);
			Vector2();

			bool operator==(const Vector2& other);

			Vector2 operator+(const Vector2& other);
			Vector2 operator-(const Vector2& other);
			Vector2 operator*(const Vector2& other);

			static Vector2 Negate(Vector2 vector);
			static float Magnitude(Vector2 vector);
			static Vector2 Normalize(Vector2 vector);

			std::string toString();
		};
	}
}


#endif