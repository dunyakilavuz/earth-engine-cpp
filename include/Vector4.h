#ifndef VECTOR4_H
#define VECTOR4_H

#include <string>
#include <sstream>

namespace eEngine
{
	namespace Maths
	{
		class Vector4
		{
		public:
			float x;
			float y;
			float z;
			float w;

			static Vector4* one;
			static Vector4* zero;

			Vector4(float x, float y, float z, float w);
			Vector4();

			Vector4 operator+(const Vector4& other);
			Vector4 operator-(const Vector4& other);
			Vector4 operator*(const Vector4& other);

			std::string toString();
		};
	}
}

#endif