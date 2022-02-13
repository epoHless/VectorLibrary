#ifndef VECTOR_HELPER_H
#define VECTOR_HELPER_H

#ifdef DLL_EXPORT
#define VECTOR_HELPER_API __declspec(dllexport)
#else
#define VECTOR_HELPER_API __declspec(dllimport)
#endif

#include <math.h>
#include "ConsoleColors.h"
#include <Windows.h>
#include <string>
#include <iostream>

enum class VectorAxis : int
{
	AXIS_X = 0,
	AXIS_Y,
	AXIS_Z
};

struct VECTOR_HELPER_API Vector
{
public:
	Vector() : x(0), y(0), z(0) {}
	Vector(const float x, const  float y, const float z) : x(x), y(y), z(z) {}
	Vector(const float x, const float y) : x(x), y(y), z(0) {}
	Vector(const float xyz) : x(xyz), y(xyz), z(xyz) {}

	float operator[](const VectorAxis index)
	{
		if (index == static_cast<VectorAxis>(0)) return x;
		if (index == static_cast<VectorAxis>(1)) return y;
		if (index == static_cast<VectorAxis>(2)) return z;

		return 0.0f;
	}

	void operator+=(const Vector rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
	}

	Vector operator+(const Vector& rhs)
	{
		Vector temp = *this;
		temp.x = x + rhs.x;
		temp.y = y + rhs.y;
		temp.z = z + rhs.z;

		return temp;
	}

	void operator-=(const Vector rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
	}

	Vector operator-(const Vector& rhs)
	{
		Vector temp = *this;
		temp.x = x - rhs.x;
		temp.y = y - rhs.y;
		temp.z = z - rhs.z;

		return temp;
	}

	void operator*=(const float rhs)
	{
		x *= rhs;
		y *= rhs;
		z *= rhs;
	}

	void operator*=(const Vector rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;
	}

	Vector& operator*(const Vector& rhs)
	{
		Vector temp = *this;
		temp.x = x * rhs.x;
		temp.y = y * rhs.y;
		temp.z = z * rhs.z;
		return temp;
	}

	Vector operator*(const float rhs)
	{
		Vector temp = *this;
		temp.x = x * rhs;
		temp.y = y * rhs;
		temp.z = z * rhs;
		return temp;
	}

	void operator/=(const float rhs)
	{
		x /= rhs;
		y /= rhs;
		z /= rhs;
	}

	void operator/=(const Vector rhs)
	{
		x /= rhs.x;
		y /= rhs.y;
		z /= rhs.z;
	}

	Vector operator/(const float rhs)
	{
		Vector temp = *this;
		temp.x = x / rhs;
		temp.y = y / rhs;
		temp.z = z / rhs;
		return temp;
	}

	Vector operator/(const Vector& rhs)
	{
		Vector temp = *this;
		temp.x = x / rhs.x;
		temp.y = y / rhs.y;
		temp.z = z / rhs.z;
		return temp;
	}

	Vector& operator--()
	{
		--x;--y;--z;
		return *this;
	}

	Vector operator--(int)
	{
		Vector temp = *this;
		operator--();
		return temp;
	}

	Vector& operator++()
	{
		++x; ++y; ++z;
		return *this;
	}

	Vector operator++(int)
	{
		Vector temp = *this;
		operator++();
		return temp;
	}

private:
	float x;
	float y;
	float z;
};

struct VECTOR_HELPER_API VectorFunc
{

	#pragma region Shorthand Functions

	/// <summary>
	/// Shorthand for writing (1,1,1)
	/// </summary>
	/// <returns></returns>
	static Vector vector_one() { return Vector(1, 1, 1); }
	/// <summary>
	/// Shorthand for writing (0,0,0)
	/// </summary>
	/// <returns></returns>
	static Vector vector_zero() { return Vector(0, 0, 0); }
	/// <summary>
	/// Shorthand for writing (0,1,0)
	/// </summary>
	/// <returns></returns>
	static Vector vector_up() { return Vector(0, 1, 0); }
	/// <summary>
	/// Shorthand for writing (0,-1,0)
	/// </summary>
	/// <returns></returns>
	static Vector vector_down() { return Vector(0, -1, 0); }
	/// <summary>
	/// Shorthand for writing (1,0,0)
	/// </summary>
	/// <returns></returns>
	static Vector vector_right() { return Vector(1, 0, 0); }
	/// <summary>
	/// Shorthand for writing (-1,0,0)
	/// </summary>
	/// <returns></returns>
	static Vector vector_left() { return Vector(-1, 0, 0); }
	/// <summary>
	/// Shorthand for writing (0,0,1)
	/// </summary>
	/// <returns></returns>
	static Vector vector_forward() { return Vector(0, 0, 1); }
	/// <summary>
	/// Shorthand for writing (0,0,-1)
	/// </summary>
	/// <returns></returns>
	static Vector vector_backwards() { return Vector(0, 0, -1); }

	#pragma endregion

	static Vector cross_product(Vector vecA, Vector vecB) { 
		return Vector((vecA[VectorAxis::AXIS_Y] * vecB[VectorAxis::AXIS_Z]) - (vecA[VectorAxis::AXIS_Z] * vecB[VectorAxis::AXIS_Y]),
					(vecA[VectorAxis::AXIS_Z] * vecB[VectorAxis::AXIS_X]) - (vecA[VectorAxis::AXIS_X] * vecB[VectorAxis::AXIS_Z]),
					(vecA[VectorAxis::AXIS_X] * vecB[VectorAxis::AXIS_Y]) - (vecA[VectorAxis::AXIS_Y] * vecB[VectorAxis::AXIS_Z])
		);
	}
	/// <summary>
	/// Returns the dot product of vecA and vecB
	/// </summary>
	/// <param name="vecA"></param>
	/// <param name="vecB"></param>
	/// <returns></returns>
	static float dot_product(Vector vecA, Vector vecB) { return ((vecA[VectorAxis::AXIS_X] * vecB[VectorAxis::AXIS_X]) + (vecA[VectorAxis::AXIS_Y] * vecB[VectorAxis::AXIS_Y]) + (vecA[VectorAxis::AXIS_Z] * vecB[VectorAxis::AXIS_Z])); }
	/// <summary>
	/// Calulate the lenght of the vector, return is the scalar of the vector
	/// </summary>
	/// <param name="vec">vector passed to calculate the lenght</param>
	/// <returns></returns>
	static float magnitude(Vector vec) { return sqrt(static_cast<double>((pow(vec[VectorAxis::AXIS_X], 2) + (pow(vec[VectorAxis::AXIS_Y],2))))); }
	/// <summary>
	/// Calculate distance from vector A to vector B
	/// </summary>
	/// <param name="a">Start vector</param>
	/// <param name="b">End vector</param>
	/// <returns></returns>
	static Vector distance(Vector origin, Vector destination) { return destination - origin; }
	/// <summary>
	/// Returns true if a > b
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	static bool is_higher(float a, float b) { return a > b; }
};

struct VECTOR_HELPER_API VectorConsole
{
	static void print_vector(Vector vector)
	{
		void* output = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(output, AXIS_X_COLOR);
		std::cout << "X: " << vector[VectorAxis::AXIS_X];
		SetConsoleTextAttribute(output, COLOR_WHITE);
		std::cout << " | ";
		SetConsoleTextAttribute(output, AXIS_Y_COLOR);
		std::cout << "Y: " << vector[VectorAxis::AXIS_Y];
		SetConsoleTextAttribute(output, COLOR_WHITE);
		std::cout << " | ";
		SetConsoleTextAttribute(output, AXIS_Z_COLOR);
		std::cout << "Z: " << vector[VectorAxis::AXIS_Z] << std::endl;
		SetConsoleTextAttribute(output, COLOR_WHITE);
	};

	static void print_vector_axis(Vector vector, VectorAxis axis)
	{
		void* output = GetStdHandle(STD_OUTPUT_HANDLE);

		switch (axis)
		{
		case VectorAxis::AXIS_X:
			SetConsoleTextAttribute(output, AXIS_X_COLOR);
			std::cout << "X: " << vector[VectorAxis::AXIS_X] << std::endl;
			SetConsoleTextAttribute(output, COLOR_WHITE);
			break;
		case VectorAxis::AXIS_Y:
			SetConsoleTextAttribute(output, AXIS_Y_COLOR);
			std::cout << "Y: " << vector[VectorAxis::AXIS_Y] << std::endl;
			SetConsoleTextAttribute(output, COLOR_WHITE);
			break;
		case VectorAxis::AXIS_Z:
			SetConsoleTextAttribute(output, AXIS_Z_COLOR);
			std::cout << "Z: " << vector[VectorAxis::AXIS_Z] << std::endl;
			SetConsoleTextAttribute(output, COLOR_WHITE);
			break;
		default:
			break;
		}
	}

};

#endif VECTOR_HELPER_H