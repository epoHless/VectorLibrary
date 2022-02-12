#include <iostream>
#include "VectorHelper.h"

int main() 
{
	Vector playerPos(20,20,20);
	Vector enemyPos(5, 5, 5);

	//Vector distance = VectorFunc::distance(playerPos, enemyPos);
	Vector newPos(10, 39);


	printf("Player x: %f, Player y: %f, Player z: %f\n",
		static_cast<float>(newPos[VectorAxis::AXIS_X]),
		static_cast<float>(newPos[VectorAxis::AXIS_Y]),
		static_cast<float>(newPos[VectorAxis::AXIS_Z])
		);

	printf("The Magnitude is: %f\n",
		VectorFunc::magnitude(newPos)
		);

	system("pause");

	return 0;
}