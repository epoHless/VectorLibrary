#pragma once
#include <stdlib.h>

static class Utilities
{
public:
	static int Random(int max)
	{
		int result = 0 + (rand() % max);
		return result;
	};
};