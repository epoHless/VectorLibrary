#include <iostream>
#include "VectorHelper.h"

int main() 
{
	Vector playerPos(20,20,20);
	Vector enemyPos(5, 5, 5);

	Vector vecA(2,3,4);
	Vector vecB(5,6,7);

	Vector crossProd(VectorFunc::cross_product(vecA, vecB));

	VectorConsole::print_vector(vecA);

	/*printf("Player x: %f, Player y: %f, Player z: %f\n",
		static_cast<float>(crossProd[VectorAxis::AXIS_X]),
		static_cast<float>(crossProd[VectorAxis::AXIS_Y]),
		static_cast<float>(crossProd[VectorAxis::AXIS_Z])
		);*/
	
	system("pause");

	return 0;
}