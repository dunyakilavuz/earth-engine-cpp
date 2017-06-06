#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Component.h"
#include "Vector3.h"
#include "Quaternion.h"
#include "Matrix4x4.h"

using namespace eEngine::Maths;

namespace eEngine
{
	namespace Components
	{
		class Transform : public Component
		{
		public:
			static const std::string typeIDS;
			virtual std::string typeID();

			Vector3* position;
			Quaternion* rotation;
			Vector3* scale;
			Matrix4x4* worldMatrix;
			
			Transform();
			
			virtual void Start();
			virtual void Update();

			void RotateAround(Vector3 point, Vector3 axis, float angle);

			Vector3 right();
			Vector3 left();
			Vector3 up();
			Vector3 down();
			Vector3 forward();
			Vector3 backward();
		};
	}
}

#endif