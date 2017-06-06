#ifndef QUATERNION_H
#define QUATERNION_H

#include "Vector3.h"

namespace eEngine
{
    namespace Maths
    {
        class Quaternion
        {
        public:
            float w;
            float x;
            float y;
            float z;

            static Quaternion* identity;
            Quaternion(float w, float x, float y, float z);
            Quaternion();

            bool operator==(const Quaternion& other);

            Quaternion operator*(const Quaternion& other);
            Vector3 operator*(const Vector3& other);

            static Quaternion AngleAxis(float angle, Vector3 axis);
            static Vector3 QuaternionToEuler(Quaternion q);
            static Quaternion EulerToQuaternion(Vector3 vector);
            static Quaternion Slerp(Quaternion start, Quaternion end, float factor);
            static Quaternion Normalize(Quaternion q);

            void normalize();
            
        };
    }
	
}

#endif