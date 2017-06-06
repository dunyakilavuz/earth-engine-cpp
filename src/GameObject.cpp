#include "GameObject.h"

using namespace eEngine::Components;
using namespace eEngine::Utils;

const std::string GameObject::typeIDS = "GameObject";

std::string GameObject::typeID()
{
	return typeIDS;
}

GameObject::GameObject()
{
	componentList = new List<Component>();
	transform = new Transform();
	AddComponent(transform);
}

void GameObject::Awake()
{

}

void GameObject::Start()
{

}

void GameObject::Update()
{

}

bool GameObject::AddComponent(Component* t)
{
	for(int i = 0; i < componentList->count; i++)
	{
		if(t->typeID() == componentList->get(i)->typeID())
		{
			return false;
		}
	}
	t->gameObject = this;
	componentList->add(t);
	return true;
}
