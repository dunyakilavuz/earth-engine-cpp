#include "Transform.h"

using namespace eEngine::Components;

const std::string Transform::typeIDS = "Transform";

std::string Transform::typeID()
{
	return typeIDS;
}


Transform::Transform()
{
	position = new Vector3(0,0,0);
	rotation = Quaternion::identity;
	scale = new Vector3(1,1,1);
	worldMatrix = new Matrix4x4();
	*worldMatrix = Matrix4x4::TranslationMatrix(*position) * (Matrix4x4::ScaleMatrix(*scale) * Matrix4x4::RotationMatrix(*rotation));
}

void Transform::Start()
{

}

void Transform::Update()
{
	*worldMatrix = Matrix4x4::TranslationMatrix(*position) * (Matrix4x4::ScaleMatrix(*scale) * Matrix4x4::RotationMatrix(*rotation));
}

void Transform::RotateAround(Vector3 point, Vector3 axis, float angle)
{	
	Vector3 direction = Vector3::Normalize(*position - point);
	float distance = Vector3::Magnitude(*position - point);

	direction = Quaternion::AngleAxis(angle,Vector3::Negate(axis)) * direction;
	*this->position = direction * distance;
	
}

Vector3 Transform::right()
{
	Vector3 temp;
	temp.x = worldMatrix->ColumnToVector4(0).x;
	temp.y = worldMatrix->ColumnToVector4(0).y;
	temp.z = worldMatrix->ColumnToVector4(0).z;
	return Vector3::Normalize(temp);	
}

Vector3 Transform::left()
{
	Vector3 temp;
	temp.x = -worldMatrix->ColumnToVector4(0).x;
	temp.y = -worldMatrix->ColumnToVector4(0).y;
	temp.z = -worldMatrix->ColumnToVector4(0).z;
	return Vector3::Normalize(temp);	
}
Vector3 Transform::up()
{
	Vector3 temp;
	temp.x = worldMatrix->ColumnToVector4(1).x;
	temp.y = worldMatrix->ColumnToVector4(1).y;
	temp.z = worldMatrix->ColumnToVector4(1).z;
	return Vector3::Normalize(temp);	
}

Vector3 Transform::down()
{
	Vector3 temp;
	temp.x = -worldMatrix->ColumnToVector4(1).x;
	temp.y = -worldMatrix->ColumnToVector4(1).y;
	temp.z = -worldMatrix->ColumnToVector4(1).z;
	return Vector3::Normalize(temp);	
}

Vector3 Transform::forward()
{
	Vector3 temp;
	temp.x = worldMatrix->ColumnToVector4(2).x;
	temp.y = worldMatrix->ColumnToVector4(2).y;
	temp.z = worldMatrix->ColumnToVector4(2).z;
	return Vector3::Normalize(temp);
}

Vector3 Transform::backward()
{
	Vector3 temp;
	temp.x = -worldMatrix->ColumnToVector4(2).x;
	temp.y = -worldMatrix->ColumnToVector4(2).y;
	temp.z = -worldMatrix->ColumnToVector4(2).z;
	return Vector3::Normalize(temp);
}
