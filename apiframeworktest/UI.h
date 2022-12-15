#pragma once
#include "Object.h"

class UI :
	public Object
{
public:
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	UI();
	~UI();
};

