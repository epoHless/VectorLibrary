#include <iostream>
#include "VectorHelper.h"

int main() 
{
	Vector playerPos(20, 20, 20);

	printf("Pos x: %f, Pos y: %f, Pos z: %f\n",
		static_cast<float>(playerPos[VectorAxis::AXIS_X]),
		static_cast<float>(playerPos[VectorAxis::AXIS_Y]),
		static_cast<float>(playerPos[VectorAxis::AXIS_Z])
	);

	system("pause");

	return 0;
}