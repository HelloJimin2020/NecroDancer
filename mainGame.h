#pragma once
#include"gameNode.h"
#include"mapTool.h"
#include"testScene.h"


#define DC gameNode::getMemDC()

class mainGame : public gameNode
{
private:

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(/*HDC hdc*/);

	void imagesInit();
};
