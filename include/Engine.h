#ifndef ENGINE_H
#define ENGINE_H

#include "References.h"
#include "Scene.h"
#include "GLFunctions.h"

namespace eEngine
{
	class Engine
	{
		Scene *activeScene;
	public:
		GLFWwindow* window;
		Engine();
		void Awake();
		void Start();
		void Update();
		void Stop();

		void setActiveScene(Scene* scene);
	};
}

#endif