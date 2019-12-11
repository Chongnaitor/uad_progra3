#pragma once
#include"CVector3.h"
class AABB_2D {
public:
	AABB_2D();
	AABB_2D(CVector3*);
	~AABB_2D();

	void getCorners(CVector3*);
	void setCorners(CVector3* inCorners);
	bool pointsInside(CVector3 *);
	CVector3 corners[4];  
	

};
