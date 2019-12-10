#include "../Include/AABB_2D.h"
AABB_2D::AABB_2D() {



}



AABB_2D::~AABB_2D() {


}


void AABB_2D::getCorners(CVector3* c) {

	*c = corners[0];    c++;
	*c = corners[1];    c++;
	*c = corners[2];    c++;
	*c = corners[3];    c++;

}


void AABB_2D::setCorners(CVector3* inCorners) {
	//TODO:
	//
	for (int i; i < 4; i++) {
		corners[i] = inCorners[i];
	}
}


bool AABB_2D::pointsInside(CVector3* Lmao) {
	CVector3 P1=Lmao[0];
	CVector3 P2=Lmao[1];
	CVector3 P3=Lmao[2];
	CVector3 P4=Lmao[3];
	CVector3 P5=Lmao[4];
	CVector3 P6=Lmao[5];
	for (int i = 0; i <= 4; i++)
	{
		if (P1.getX() >= corners[i].getX() && P1.getX() <= corners[i].getX())
		{


			return true;
		}

		if (P2.getX() >= corners[i].getX() && P2.getX() <= corners[i].getX())
		{


			return true;
		}
		if (P3.getX() >= corners[i].getX() && P3.getX() <= corners[i].getX())
		{


			return true;
		}
	
		if (P4.getX() >= corners[i].getX() && P4.getX() <= corners[i].getX())
		{


			return true;
		}
		if (P5.getX() >= corners[i].getX() && P5.getX() <= corners[i].getX())
		{


			return true;
		}
		if (P6.getX() >= corners[i].getX() && P6.getX() <= corners[i].getX())
		{


			return true;
		}

		if (P1.getY() >= corners[i].getY() && P1.getY() <= corners[i].getY())
		{


			return true;
		}

		if (P2.getY() >= corners[i].getY() && P2.getY() <= corners[i].getY())
		{


			return true;
		}
		if (P3.getY() >= corners[i].getY() && P3.getY() <= corners[i].getY())
		{


			return true;
		}

		if (P4.getY() >= corners[i].getY() && P4.getY() <= corners[i].getY())
		{


			return true;
		}
		if (P5.getY() >= corners[i].getY() && P5.getY() <= corners[i].getY())
		{


			return true;
		}
		if (P6.getY() >= corners[i].getY() && P6.getY() <= corners[i].getY())
		{


			return true;
		}
	}






	return false;
}
