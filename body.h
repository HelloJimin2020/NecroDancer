#pragma once
#include"item.h"
class body : public item
{
private:
	int _power;

public:
	body();
	body(string name, slotType type, int power, string description);
	~body();


	void update() override;

};
