#define PI 3.14159265
class MathHelper
{
public:

	//Convert an angle from radians into degrees
	static double toDegrees(const double &rads)
	{
		return rads * 180.0 / PI;
	}
};