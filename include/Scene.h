#ifndef SCENE_H
#define SCENE_H

#include "GLFunctions.h"
#include "List.h"
#include "GameObject.h"
#include "ShaderProgram.h"
#include "Loader.h"
#include "File.h"
#include "Camera.h"

using namespace eEngine::Components;
using namespace eEngine::Utils; 
using namespace eEngine::Graphics;

namespace eEngine
{
	class Scene
	{
		GameObject* mainCamera;
		List<GameObject> *gameObjectList;
		ShaderProgram *shader;
		GameObject* origin;
	public:
		Scene();
		void Awake();
		void Start();
		void Update();

		void AddGameObject(GameObject *gameObject);

		int gameObjectCount();
		void drawGrid();
	};
}

#endif