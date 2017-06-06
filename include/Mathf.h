#ifndef MATHF_H
#define MATHF_H

namespace eEngine
{
	namespace Maths
	{
		class Mathf
		{
		public:
			static const float PI;
			static const float DegToRad;
			static const float RadToDeg;

			static float Lerp(float start,float end,float factor);
			static float Cos(float radian);
			static float Sin(float radian);
			static float Tan(float radian);
			static float Atan2(float y, float x);
			static float Asin(float radian);
			static float Acos(float radian);
			static float Clamp(float value, float minimum, float maximum);
			static float Min(float a, float b);
			static float Max(float a, float b);
			static float Sqrt(float value);
		};
	}
}

#endif