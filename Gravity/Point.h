#pragma once
#include <type_traits>
#include <cmath>
template <class T> 
class Point
{
public:

	Point(T x, T y)
		: x(x), y(y)
	{
		static_assert(std::is_arithmetic<T>::value, "Position values must be numeric!");
	}
	~Point()
	{
	}


	inline T getX() const
	{
		return x;
	}
	inline T getY() const
	{
		return y;
	}
	inline void setX(T xNew)
	{
		x = xNew;
	}
	inline void  setY(T yNew)
	{
		y = yNew;
	}

	//Returns absolute distance to another point as a double
	double distanceTo(const Point<T> &p) const
	{
		return sqrt(pow((p.x - this->x), 2) + pow((p.y - this->y), 2));
	}

	//Returns angle to another point as a double in radians
	double angleTo(const Point<T> &p) const
	{
		T adj = abs(p.x - this->x);
		double hyp = distanceTo(p);

		return acos(adj / hyp);
	}




private:
	T x;
	T y;
	
};

