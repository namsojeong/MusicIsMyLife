#include "pch.h"
#include "Scene.h"
#include "Object.h"
#include "ResMgr.h"
#include "Image.h"

void Scene::SetBackground(wstring _strName, wstring _path)
{
	if (_strName == L"")
	{
		_strName = L"Background_Default";
		_path = L"Image\\Default_Background.bmp";
	}
	m_background = ResMgr::GetInst()->ImgLoad(_strName, _path);
}

void Scene::Update()
{
	
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; i++)
	{
		for (size_t j = 0; j < m_vecObj[i].size(); j++)
		{
			if (!m_vecObj[i][j]->IsDead())
				m_vecObj[i][j]->Update();
		}
	}
	for (UINT i = 0; i < (UINT)UI_TYPE::END; i++)
	{
		for (size_t j = 0; j < m_vecUI[i].size(); j++)
		{
			m_vecUI[i][j]->Update();
		}
	}
}

void Scene::FinalUpdate()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; i++)
	{
		for (size_t j = 0; j < m_vecObj[i].size(); j++)
		{
			m_vecObj[i][j]->FinalUpdate();
		}
	}
	for (UINT i = 0; i < (UINT)UI_TYPE::END; i++)
	{
		for (size_t j = 0; j < m_vecUI[i].size(); j++)
		{
			m_vecUI[i][j]->FinalUpdate();
		}
	}
}

void Scene::Render(HDC _dc)
{
	int Width = (int)m_background->GetWidth();
	int Height = (int)m_background->GetHeight();

	TransparentBlt(_dc
		, (int)(0 - (float)(Width / 2))
		, (int)(0 - (float)(Height / 2))
		, Width, Height
		, m_background->GetDC()
		, 0, 0, Width, Height
		, RGB(255, 0, 255));



	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; i++)
	{
		vector<Object*>::iterator iter = m_vecObj[i].begin();
		for (; iter != m_vecObj[i].end();)
		{
			if (!(*iter)->IsDead())
			{
				(*iter)->Render(_dc);
				iter++;
			}
			else
			{
				iter = m_vecObj[i].erase(iter);
			}
		}
	}
	
	for (UINT i = 0; i < (UINT)UI_TYPE::END; i++)
	{
		vector<Object*>::iterator iter = m_vecUI[i].begin();
		for (; iter != m_vecUI[i].end();)
		{
			if (!(*iter)->IsDead())
			{
				(*iter)->Render(_dc);
				iter++;
			}
			else
			{
				iter = m_vecUI[i].erase(iter);
			}
		}
	}

	
}

void Scene::DeleteGroup(GROUP_TYPE _eTarget)
{
	for (size_t i = 0; i < m_vecObj[(UINT)_eTarget].size(); i++)
	{
		delete m_vecObj[(UINT)_eTarget][i];
	}
	m_vecObj[(UINT)_eTarget].clear();
//	Safe_Delete_Vec(m_vecObj[(UINT)_eTarget]);
	//Safe_Delete_Vec<Object*>(m_vecObj[(UINT)_eTarget]);

}

void Scene::DeleteUIGroup(UI_TYPE _eTarget)
{
	for (size_t i = 0; i < m_vecObj[(UINT)_eTarget].size(); i++)
	{
		delete m_vecUI[(UINT)_eTarget][i];
	}
	m_vecUI[(UINT)_eTarget].clear();
}

void Scene::DeleteAll()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; i++)
	{
		DeleteGroup((GROUP_TYPE)i);
	}
	
	for (UINT i = 0; i < (UINT)UI_TYPE::END; i++)
	{
		DeleteUIGroup((UI_TYPE)i);
	}

}

Scene::Scene()
{
	
}

Scene::~Scene()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; i++)
	{
		for (size_t j = 0; j < m_vecObj[i].size(); j++)
		{
			delete m_vecObj[i][j];
		}
	}
}
