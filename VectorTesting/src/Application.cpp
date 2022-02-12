#include <iostream>
#include "VectorHelper.h"

int main() 
{
	Vector playerPos(20,20,20);

	printf("Player x: %f, Player y: %f, Player z: %f",
		static_cast<float>(playerPos[VectorAxis::AXIS_X]),
		static_cast<float>(playerPos[VectorAxis::AXIS_Y]),
		static_cast<float>(playerPos[VectorAxis::AXIS_Z])
		);

	system("pause");

	return 0;
}