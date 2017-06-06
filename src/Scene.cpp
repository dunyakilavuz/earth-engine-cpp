#include "Scene.h"

using namespace eEngine;

Scene::Scene()
{
	mainCamera = new GameObject();
	mainCamera->name = "mainCamera";
	mainCamera->AddComponent(new Camera(mainCamera));
	origin = new GameObject();
	gameObjectList = new List<GameObject>();
}

void Scene::Awake()
{
	shader = new ShaderProgram();
	shader->createVertexShader(Loader::ImportCode(References::projectPath() + "\\res\\shaders\\vertex.vs"));
	shader->createFragmentShader(Loader::ImportCode(References::projectPath() + "\\res\\shaders\\fragment.fs"));
	shader->Link();
	shader->createUniform("projectionMatrix");
	shader->createUniform("modelViewMatrix");
	shader->createUniform("texture_sampler");
	shader->createUniform("colour");
	shader->createUniform("useColour");

	for(int i = 0; i < gameObjectList->count; i++)
	{
		gameObjectList->get(i)->Awake();
	}

	*mainCamera->transform->position = Vector3(0,3,10);
	mainCamera->Update();
}

void Scene::Start()
{
	for(int i = 0; i < gameObjectList->count; i++)
	{
		gameObjectList->get(i)->Start();
	}
}

void Scene::Update()
{
	shader->Bind();
	shader->setUniform("projectionMatrix", *mainCamera->GetComponent<Camera>()->projectionMatrix);

	drawGrid();

	for(int i = 0; i < gameObjectList->count; i++)
	{
		gameObjectList->get(i)->Update();
	}
}

void Scene::AddGameObject(GameObject *gameObject)
{
	gameObjectList->add(gameObject);
}

int Scene::gameObjectCount()
{
	return gameObjectList->count;
}

void Scene::drawGrid()
{
	glBegin(GL_LINES);
	for(int i = -10; i < 11; i++)
	{			
		glVertex3f(-10, 0, i);
		glVertex3f(10, 0, i);
			
		glVertex3f(i, 0, -10);
		glVertex3f(i, 0, 10);
	}
	glEnd();
}