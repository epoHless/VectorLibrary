#include <iostream>
#include "VectorHelper.h"

int main() 
{
	Vector playerPos(20,20,20);
	Vector enemyPos(5, 5, 5);

	//Vector distance = VectorFunc::distance(playerPos, enemyPos);
	Vector vecA(-6, 8);
	Vector vecB(5, 12);


	printf("Player x: %f, Player y: %f, Player z: %f\n",
		static_cast<float>(vecA[VectorAxis::AXIS_X]),
		static_cast<float>(vecA[VectorAxis::AXIS_Y]),
		static_cast<float>(vecA[VectorAxis::AXIS_Z])
		);

	printf("The Dot product is: %f\n",
		VectorFunc::dot_product(vecA, vecB)
		);

	system("pause");

	return 0;
}