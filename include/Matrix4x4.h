#ifndef MATRIX4X4_H
#define MATRIX4X4_H

#include "Vector3.h"
#include "Vector4.h"
#include "Quaternion.h"
#include "Camera.h"

using namespace eEngine::Components;

namespace eEngine
{
    namespace Maths
    {
        class Matrix4x4
        {
        public:
            float matrix[4][4];

            bool operator==(const Matrix4x4& other);

            Matrix4x4 operator+(const Matrix4x4& other);
            Matrix4x4 operator-(const Matrix4x4& other);
            Matrix4x4 operator*(const Matrix4x4& other);

            void Vector4ToRow(int row, Vector4 vector);
            Vector4 RowToVector4(int row);
            Vector4 ColumnToVector4(int column);
            
            static float* Serialized(Matrix4x4 matrix, float toFill[]);

            static Matrix4x4 ProjectionMatrix(Camera* camera);
            static Matrix4x4 ViewMatrix(Camera* camera);
            
            static Matrix4x4 TranslationMatrix(Vector3 vector);
            static Matrix4x4 RotationMatrix(Quaternion q);
            static Matrix4x4 ScaleMatrix(Vector3 vector);

            static Matrix4x4 IdentityMatrix();
        };
    }
	
}
#endif