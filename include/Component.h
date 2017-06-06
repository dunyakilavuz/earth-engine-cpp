#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>
#include <string>

namespace eEngine
{
	namespace Components
	{
		class GameObject;

		class Component
		{
		public:
			bool isActive;
			static const std::string typeIDS;
			virtual std::string typeID() = 0;
			GameObject* gameObject;
			
			void Awake();
			virtual void Start();
			virtual void Update();
			
		};
	}
}


#endif