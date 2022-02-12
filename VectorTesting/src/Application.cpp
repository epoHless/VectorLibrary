#include <iostream>
#include "VectorHelper.h"

int main() 
{
	Vector playerPos(20,20,20);
	Vector newPos(10,10,10);

	Vector tempPos = playerPos + newPos;

	printf("Player x: %f, Player y: %f, Player z: %f",
		static_cast<float>(tempPos[VectorAxis::AXIS_X]),
		static_cast<float>(tempPos[VectorAxis::AXIS_Y]),
		static_cast<float>(tempPos[VectorAxis::AXIS_Z])
		);


	system("pause");

	return 0;
}