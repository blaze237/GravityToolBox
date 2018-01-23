#include "Point.h"

template<class T>
Point:Point(T x, T y)
	: x(x), y(y)
{

}

Point:~Point()
{
}

template<class T>
inline T Point : getX()
{
	return x;
}

template<class T>
inline T Point : getY()
{
	return y;
}



template<class T>
inline void Point : setX(T x)
{

	this.x = x;
}

template<class T>
inline void Point : setY(T y)
{

	this.y = y;
}


