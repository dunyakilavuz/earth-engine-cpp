#include "Engine.h"
#include "Debug.h"

using namespace eEngine;

Engine::Engine()
{
	if(!glfwInit())
	{
		Debug::Log("Failed to initialize GLFW.");
	}

	if(!glewInit())
	{
		Debug::Log("Failed to initialize GLEW.");
	}
	

	window = glfwCreateWindow(References::WindowWidth, 
							References::WindowHeight,
	 						References::WindowTitle.c_str(), NULL, NULL);		 
	if (!window)
    {
        glfwTerminate();
        Debug::Log("Failed to initialize window.");
    }
	glfwMakeContextCurrent(window);

	glewInit();

}

void Engine::Awake()
{
	activeScene->Awake();
}

void Engine::Start()
{
	activeScene->Start();
}

void Engine::Update()
{
	while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
	activeScene->Update();
}

void Engine::Stop()
{
	glfwTerminate();
}

void Engine::setActiveScene(Scene* scene)
{
	activeScene = scene;
}