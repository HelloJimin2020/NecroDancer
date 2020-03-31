#pragma once
#include "gameNode.h"

class introScene : public gameNode
{
private:
	image* _intro;
	tagButton _button[3];

	RECT _check;
	int _buttonNum;
public:
	introScene();
	~introScene();

	HRESULT init();
	void release();
	void update();
	void render(/*HDC hdc*/);


};

