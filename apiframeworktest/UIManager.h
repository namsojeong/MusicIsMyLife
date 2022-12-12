#pragma once
class UI;
class UIManager
{
public:
	SINGLE(UIManager);
private:
	UIManager();
	~UIManager();
private:
	UI* m_arrUI[(UINT)UI_TYPE::END];
private:
	void	 Init();
	void	 Update();
	void	 Render(HDC _dc);

};

