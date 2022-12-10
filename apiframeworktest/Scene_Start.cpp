#include "pch.h"
#include "Scene_Start.h"
#include "KeyMgr.h"

Scene_Start::Scene_Start()
{
}

Scene_Start::~Scene_Start()
{
}

void Scene_Start::Enter()
{
	
}

void Scene_Start::Exit()
{
	
}

void Scene_Start::Update()
{  
	if (KEY_HOLD(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::GAME);
	}
}
