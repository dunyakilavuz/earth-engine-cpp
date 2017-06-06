#include "Engine.h"
#include "GameObject.h"
#include <iostream>
#include <string>

using namespace eEngine;
using namespace eEngine::Utils;
using namespace std;

int main(void)
{
    Engine *engine = new Engine();
    Scene *scene = new Scene();

    engine->setActiveScene(scene);
    engine->Awake();
    engine->Start();
    engine->Update();
    engine->Stop();

    return 0;
}