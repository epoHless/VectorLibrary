#include <iostream>
#include "VectorHelper.h"

int main() 
{
	Vector playerPos(20,20,20);
	Vector enemyPos(5, 5, 5);

	Vector distance = VectorFunc::distance(playerPos, enemyPos);

	printf("Player x: %f, Player y: %f, Player z: %f",
		static_cast<float>(distance[VectorAxis::AXIS_X]),
		static_cast<float>(distance[VectorAxis::AXIS_Y]),
		static_cast<float>(distance[VectorAxis::AXIS_Z])
		);

	system("pause");

	return 0;
}