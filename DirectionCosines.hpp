/************************
* Direction Cosines Class
* Will be used in Line and Point class to perform different operations.
*
*************************/
#ifndef INC_DIRECTIONCOSINES_H
#define INC_DIRECTIONCOSINES_H

#include <float.h>

/// Class to define the direction cosines in 3d space
class DirectionCosines
{ 
public:
	/// Class might be initialized with direction cosines or ratios, to make it inclusive of both.
    DirectionCosines(float a, float b, float c);
	~DirectionCosines();

	/// cosine of the angle made by the line/segment with the x-axis
	float xl;
	/// cosine of the angle made by the line/segment with the y-axis
	float yl;
	/// cosine of the angle made by the line/segment with the z-axis
	float zl;


    float dotProduct(DirectionCosines l);
    DirectionCosines crossProduct(DirectionCosines l);

};

#endif  /* INC_DIRECTIONCOSINES_H */

