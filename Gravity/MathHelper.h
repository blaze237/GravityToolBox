class MathHelper
{
public:

	static const double PI;

	//Convert an angle from radians into degrees
	static double toDegrees(const double &rads)
	{
		return rads * 180.0 / PI;
	}
};