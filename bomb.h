#pragma once
#include"item.h"
class bomb :public item
{
private:
	int _num;
	image* _ani;
	bool _isFire;
	int _power;
	int _frameX;
	int bombX, bombY , bombTile;
public:
	bomb();
	bomb(string name, slotType type, int num, string description, int x, int y, int price);
	~bomb();
	virtual HRESULT init() override;

	void update() override;
	void render(HDC hdc) override;
	void active() override;
	void setValue(int num) override;
	int getValue() override;
};

