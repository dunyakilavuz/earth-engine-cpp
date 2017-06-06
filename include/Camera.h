#ifndef CAMERA_H
#define CAMERA_H

#include "Component.h"
#include "References.h"
#include "Mathf.h"

using namespace eEngine::Maths;

namespace eEngine
{
	namespace Maths
	{
		class Matrix4x4;
	}

	namespace Components
	{
		class GameObject;
	}
}

namespace eEngine
{
	namespace Components
	{
		class Camera : public Component
		{
		public:
			static const std::string typeIDS;
			virtual std::string typeID();
			GameObject* gameObject;
			Camera(GameObject* parent);
			float aspectRatio;
			float fieldOfView;
			float farClipPlane;
			float nearClipPlane;
			Matrix4x4* projectionMatrix;
			Matrix4x4* viewMatrix;

			void Awake();
			void Start();
			void Update();
		};
	}
}

#endif