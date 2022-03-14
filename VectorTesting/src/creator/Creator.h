#pragma once
#include "../gameobjects/GameObject.h"

class Creator
{
public:
	virtual ~Creator(){};
	virtual GameObject* FactoryMethod() const = 0;
};