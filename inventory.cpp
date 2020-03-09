#include "stdafx.h"
#include "inventory.h"


inventory::inventory()
{
}


inventory::~inventory()
{
}

HRESULT inventory::init()
{
	//_vItem.push_back(ITEMMANAGER->addItem("�⺻��"));
	return S_OK;
}

void inventory::release()
{
}

void inventory::update()
{
	for (int i = 0; i < _vItem.size(); ++i)
	{
		_vItem[i]->update();
	}
}

void inventory::render(HDC hdc)
{
	for (int i = 0; i < _vItem.size(); ++i)
	{
		_vItem[i]->render(CAMERAMANAGER->getCameraDC());
	}
}

void inventory::addItem(item * item)
{
	_vItem.push_back(item);
	for (int i = 0; i < _vItem.size(); ++i)
	{
		_vItem[i]->setInven(true);
		_vItem[i]->setRect(PointMake(30+i * 66, 20));
		_vItem[i]->rcSet();
	}
}

void inventory::swapItem(int arrNum, item*& item)
{
	_vItem[arrNum]->setInven(false);

	swap(_vItem[arrNum], item);

	//�̺κ��Լ�ȭ�Ҽ������� �Լ�ȭ �غ���. ��ź ��ġ �����ؾߵ�
	for (int i = 0; i < _vItem.size(); ++i)
	{
		_vItem[i]->setInven(true);
		_vItem[i]->setRect(PointMake(30 + i * 66, 20));
		_vItem[i]->rcSet();
	}
}