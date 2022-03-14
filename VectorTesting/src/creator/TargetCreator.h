#pragma once
#include "Creator.h"
#include "../gameobjects/Target.h"

class TargetCreator : public Creator
{
public:
	GameObject* FactoryMethod() const override
	{
		return new Target();
	}
};