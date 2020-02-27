#include "stdafx.h"
#include "mainGame.h"


mainGame::mainGame(){}

mainGame::~mainGame(){}

HRESULT mainGame::init()
{
	gameNode::init(true);
	imagesInit();

	PLAYER->init(getMemDC());
	SCENEMANAGER->addScene("����", new mapTool);
	SCENEMANAGER->addScene("�׽�Ʈ��", new testScene);
	SCENEMANAGER->changeScene("�׽�Ʈ��");
	ANIMATIONMANAGER->init();
	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	PLAYER->release();
	SCENEMANAGER->release();

}

void mainGame::update()
{
	gameNode::update();
	ANIMATIONMANAGER->update();
	SCENEMANAGER->update();
	PLAYER->update();
}

void mainGame::render(/*HDC hdc*/)
{
	//��� ��Ʈ��
	//PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	PatBlt(getMemDC(), CAMERAMANAGER->getCameraCenter().x - WINSIZEX / 2, CAMERAMANAGER->getCameraCenter().y - WINSIZEY / 2, WINSIZEX, WINSIZEY, WHITENESS);
	PatBlt(CAMERAMANAGER->getCameraDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//============================================================================�� ���� �ǵ帮�� ����=======================================================================================
	

	ANIMATIONMANAGER->render();
	SCENEMANAGER->render();
	PLAYER->render(getMemDC());
	TIMEMANAGER->render(CAMERAMANAGER->getCameraDC());



	//============================================================================�� ������ �ǵ帮�� ����=======================================================================================
	//������� ������ HDC�� �׸���.(��������!!)
	//this->getBackBuffer()->render(getHDC(), 0, 0);
	CAMERAMANAGER->render(this->getBackBuffer());
	this->getBackBuffer()->render(getHDC(), 0, 0, CAMERAMANAGER->getCameraCenter().x - WINSIZEX / 2, CAMERAMANAGER->getCameraCenter().y - WINSIZEY / 2, WINSIZEX, WINSIZEY);
}










