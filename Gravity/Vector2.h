#pragma once
#include <type_traits>
#include <cmath>
template <class T> 
class Vector2
{
public:

	Vector2(T x, T y)
		: x(x), y(y)
	{
		static_assert(std::is_arithmetic<T>::value, "Position values must be numeric!");
		length = sqrt(pow(x, 2) + pow(y, 2));
	}

	Vector2()
		:x(0), y(0)
	{

	}

/***OPERATORS ***/
	//Addition operator
	Vector2 operator+(const Vector2 &p2) const
	{
		Vector2 tmp;
		tmp.x = this->x + p2.x;
		tmp.y = this->y + p2.y;

		return tmp;
	}

	//Subtraction operator
	Vector2 operator-(const Vector2 &p2) const
	{
		Vector2 tmp;
		tmp.x = this->x - p2.x;
		tmp.y = this->y - p2.y;

		return tmp;
	}

	//Numeric division operator
	Vector2 operator/(const T &d) const
	{
		Vector2 tmp;
		tmp.x = this->x / d;
		tmp.y = this->y / d;

		return tmp;
	}

	//Numeric multiplication operator
	Vector2 operator*(const T &m) const
	{
		Vector2 tmp;
		tmp.x = this->x * m;
		tmp.y = this->y * m;

		return tmp;
	}
	//Addition assignment operator
	Vector2& operator+=(const Vector2 &p2)
	{
		this->x += p2.x;
		this->y += p2.y;
		this->length = sqrt(pow(x, 2) + pow(y, 2));
		return *this;
	}
	//Subtraction assignment operator
	Vector2& operator-=(const Vector2 &p2)
	{
		this->x -= p2.x;
		this->y -= p2.y;
		return *this;
	}
	//Multiplication assignment operator
	Vector2& operator*=(const T &m)
	{
		this->x *= m;
		this->y *= m;
		this->length = sqrt(pow(x, 2) + pow(y, 2));
		return *this;
	}
	//Division assignment operator
	Vector2& operator/=(const T &d)
	{
		this->x /= d;
		this->y /= d;
		return *this;
	}

	

/***MEMBER FUNCTIONS***/
	//Returns absolute distance to another point as a double
	double distanceTo(const Vector2<T> &p) const
	{
		return sqrt(pow((p.x - this->x), 2) + pow((p.y - this->y), 2));
	}

	//Returns angle to another point as a double in radians
	double angleTo(const Vector2<T> &p) const
	{
		T adj = abs(p.x - this->x);
		double hyp = distanceTo(p);

		return acos(adj / hyp);
	}


/***GETTERS AND SETTERS ***/
	inline T getX() const
	{
		return x;
	}
	inline T getY() const
	{
		return y;
	}
	inline T getLength() const
	{
		return length;
	}
	inline void setX(T xNew)
	{
		x = xNew;
		length = sqrt(pow(x, 2) + pow(y, 2));

	}
	inline void  setY(T yNew)
	{
		y = yNew;
		length = sqrt(pow(x, 2) + pow(y, 2));
	}


private:
	T x;
	T y;
	T length;
	
};

