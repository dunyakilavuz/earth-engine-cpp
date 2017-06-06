#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Component.h"
#include "List.h"
#include "Transform.h"

namespace eEngine
{
	namespace Components
	{
		class GameObject
		{
			Utils::List<Component> *componentList;
		public:
			static const std::string typeIDS;
			virtual std::string typeID();

			GameObject();
			Transform* transform;
			std::string name;

			void Awake();
			void Start();
			void Update();

			bool AddComponent(Component* t);

			template<class T>
			T* GetComponent();
		};


		template<class T>
		T* GameObject::GetComponent()
		{
			for(int i = 0; i < componentList->count; i++)
			{
				if(T::typeIDS == componentList->get(i)->typeID())
				{
					return static_cast<T*>(componentList->get(i));
				}
			}
			return nullptr;
		}
	}
}

#endif