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


bool AABB_2D::pointsInside(CVector3[4]) {
	//TODO:
	//Si cualquier punto esta dentro de los limites y devolver true
	//Si no pos false
	return false;
}
