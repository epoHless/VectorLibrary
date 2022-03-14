#pragma once
#include "Creator.h"
#include "../gameobjects/Bomb.h"

class BombCreator : public Creator
{
public:
	GameObject* FactoryMethod() const override
	{
		return new Bomb();
	}
};