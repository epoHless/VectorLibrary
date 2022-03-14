#pragma once
#include "manager/GameManager.h"

int main() 
{
	GameManager::GetInstance()->Run();
	return 0;
}