/************************
* Direction Cosines Class
* Will be used in Line and Point class to perform different operations.
*
*************************/
#ifndef INC_DIRECTIONCOSINES_H
#define INC_DIRECTIONCOSINES_H

/// Class to define the direction cosines in 3d space
class DirectionCosines
{ 
public:
	/// Class might be initialized with direction cosines or ratios, to make it inclusive of both.
    DirectionCosines(double a, double b, double c);
	~DirectionCosines();

	/// cosine of the angle made by the line/segment with the x-axis
    double xl;
	/// cosine of the angle made by the line/segment with the y-axis
    double yl;
	/// cosine of the angle made by the line/segment with the z-axis
    double zl;


    double dotProduct(DirectionCosines l);
    DirectionCosines crossProduct(DirectionCosines l);
    double scalarTripleProduct(DirectionCosines l1, DirectionCosines l2);
    double vectorTripleProduct(DirectionCosines l1, DirectionCosines l2);

};

#endif  /* INC_DIRECTIONCOSINES_H */

