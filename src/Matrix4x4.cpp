#include "Matrix4x4.h"
#include "GameObject.h"
#include "Debug.h"

using namespace eEngine::Maths;
using namespace eEngine::Utils;

bool Matrix4x4::operator==(const Matrix4x4& other)
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			if(this->matrix[i][j] != other.matrix[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4& other)
{
    Matrix4x4 newMatrix;

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            newMatrix.matrix[i][j] = this->matrix[i][j] + other.matrix[i][j]; 
        }
    }
    return newMatrix;
}

Matrix4x4 Matrix4x4::operator-(const Matrix4x4& other)
{
    Matrix4x4 newMatrix;

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            newMatrix.matrix[i][j] = this->matrix[i][j] - other.matrix[i][j]; 
        }
    }
    return newMatrix;
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& other)
{
    Matrix4x4 newMatrix;
		
	for (int i = 0; i < 4; i++) 
	{ 
	    for (int j = 0; j < 4; j++)
	    { 
	        for (int k = 0; k < 4; k++) 
	        { 
	            newMatrix.matrix[i][j] += this->matrix[i][k] * other.matrix[k][j];
	        }
	    }
	}
	return newMatrix;
}

void Matrix4x4::Vector4ToRow(int row, Vector4 vector)
{
    matrix[row][0] = vector.x;
	matrix[row][1] = vector.y;
	matrix[row][2] = vector.z;
	matrix[row][3] = vector.w;
}

Vector4 Matrix4x4::RowToVector4(int row)
{
	Vector4 temp;
	temp.x = matrix[row][0];
	temp.y = matrix[row][1];
	temp.z = matrix[row][2];
	temp.w = matrix[row][3];
	return temp;							
}

Vector4 Matrix4x4::ColumnToVector4(int column)
{
	Vector4 temp;
	temp.x = matrix[0][column];
	temp.y = matrix[1][column];
	temp.z = matrix[2][column];
	temp.w = matrix[3][column];
	return temp;
}

float* Matrix4x4::Serialized(Matrix4x4 matrix, float toFill[])
{		
	int counter = 0;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			toFill[counter] = matrix.matrix[j][i];
			counter++;
		}
	}
	return toFill;
}

Matrix4x4 Matrix4x4::ProjectionMatrix(Camera* camera)
{
	Matrix4x4 matrix;
	matrix.Vector4ToRow(0, Vector4((float) (1.0f /(camera->aspectRatio * Mathf::Tan(camera->fieldOfView/2))),0,0,0));
	matrix.Vector4ToRow(1, Vector4(0,(float) (1 / Mathf::Tan(camera->fieldOfView/2)),0,0));
	matrix.Vector4ToRow(2, Vector4(0,0, 
				-(camera->farClipPlane + camera->nearClipPlane) / (camera->farClipPlane - camera->nearClipPlane), 
				-(2 * camera->farClipPlane * camera->nearClipPlane) / (camera->farClipPlane - camera->nearClipPlane)));
	matrix.Vector4ToRow(3, Vector4(0,0,-1,0));
	return matrix;
}

Matrix4x4 Matrix4x4::ViewMatrix(Camera* camera)
{
	Matrix4x4 matrix;

	if(camera->gameObject == nullptr)
	{
		Debug::Log("Camera's parent is unreachable.");
	}
	
	Matrix4x4 translation = Matrix4x4::TranslationMatrix(*camera->gameObject->transform->position);
	Matrix4x4 rotation = Matrix4x4::RotationMatrix(*camera->gameObject->transform->rotation);
	matrix = translation * rotation;
 
	return matrix;
}

Matrix4x4 Matrix4x4::TranslationMatrix(Vector3 vector)
{
    Matrix4x4 newMatrix;
	newMatrix.Vector4ToRow(0, Vector4(1,0,0,vector.x));
	newMatrix.Vector4ToRow(1, Vector4(0,1,0,vector.y));
	newMatrix.Vector4ToRow(2, Vector4(0,0,1,vector.z));
	newMatrix.Vector4ToRow(3, Vector4(0,0,0,1));
	return newMatrix;
}


Matrix4x4 Matrix4x4::RotationMatrix(Quaternion q)
{
    Matrix4x4 newMatrix;
	Matrix4x4 matrix1;
	Matrix4x4 matrix2;
		
	matrix1.Vector4ToRow(0, Vector4(q.w,q.z,-q.y,q.x));
	matrix1.Vector4ToRow(1, Vector4(-q.z,q.w,q.x,q.y));
	matrix1.Vector4ToRow(2, Vector4(q.y,-q.x,q.w,q.z));
	matrix1.Vector4ToRow(3, Vector4(-q.x,-q.y,-q.z,q.w));
		
	matrix2.Vector4ToRow(0, Vector4(q.w,q.z,-q.y,-q.x));
	matrix2.Vector4ToRow(1, Vector4(-q.z,q.w,q.x,-q.y));
	matrix2.Vector4ToRow(2, Vector4(q.y,-q.x,q.w,-q.z));
	matrix2.Vector4ToRow(3, Vector4(q.x,q.y,q.z,q.w));
		
	newMatrix = matrix1 * matrix2;
	return newMatrix;
}

Matrix4x4 Matrix4x4::ScaleMatrix(Vector3 vector)
{
    Matrix4x4 newMatrix;
	newMatrix.Vector4ToRow(0, Vector4(vector.x,0,0,0));
	newMatrix.Vector4ToRow(1, Vector4(0,vector.y,0,0));
	newMatrix.Vector4ToRow(2, Vector4(0,0,vector.z,0));
	newMatrix.Vector4ToRow(3, Vector4(0,0,0,1));
	return newMatrix;
}

Matrix4x4 Matrix4x4::IdentityMatrix()
{
    Matrix4x4 newMatrix;
	newMatrix.Vector4ToRow(0, Vector4(1,0,0,0));
	newMatrix.Vector4ToRow(1, Vector4(0,1,0,0));
	newMatrix.Vector4ToRow(2, Vector4(0,0,1,0));
	newMatrix.Vector4ToRow(3, Vector4(0,0,0,1));
	return newMatrix;
}