#include "Camera.h"
#include "Matrix4x4.h"

using namespace eEngine::Components;
using namespace eEngine::Maths;

const std::string Camera::typeIDS = "Camera";

std::string Camera::typeID()
{
	return typeIDS;
}

Camera::Camera(GameObject* parent)
{
	gameObject = parent;
	aspectRatio = (float)References::WindowWidth / (float)References::WindowHeight;
	fieldOfView = Mathf::DegToRad * 60;
	farClipPlane = 1000;
	nearClipPlane = 0.1f;
	projectionMatrix = new Matrix4x4();
	viewMatrix = new Matrix4x4();
	*projectionMatrix = Matrix4x4::ProjectionMatrix(this);
	*viewMatrix = Matrix4x4::ViewMatrix(this);
}

void Camera::Awake()
{

}

void Camera::Start()
{

}

void Camera::Update()
{
	*viewMatrix = Matrix4x4::ViewMatrix(this);
}