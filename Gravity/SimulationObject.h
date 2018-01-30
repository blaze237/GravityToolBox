#pragma once
class SimulationObject
{
public:
	SimulationObject();
	~SimulationObject();

	//All displayable objects must be this class. The class is not intended to be subclassed for different object types. The reason for this, is that by only using this class, we can safely store all objects in contiguous array style memory without dervided class slicing issues.
	//There will be parts of this class that some simulations wont need or use, this is intended. Whilst less synaticly clear, the performance gained from elimating cache misses justifies this for such high perormance simulations. 

	//At some point, this will be replaced by allowing subclasses in conjunction with contiguous memory throught the use of memory pools when creating objects.
};

