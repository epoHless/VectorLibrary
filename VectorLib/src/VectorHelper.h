#ifndef VECTOR_HELPER_H
#define VECTOR_HELPER_H

#ifdef DLL_EXPORT
#define VECTOR_HELPER_API __declspec(dllexport)
#else
#define VECTOR_HELPER_API __declspec(dllimport)
#endif

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

	static Vector zero() { return Vector(0, 0, 0); }
	static Vector one() { return Vector(1, 1, 1); }

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

	Vector operator/(const float rhs)
	{
		Vector temp = *this;
		temp.x = x / rhs;
		temp.y = y / rhs;
		temp.z = z / rhs;
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

#endif VECTOR_HELPER_H