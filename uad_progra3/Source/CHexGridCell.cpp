
#include "../stdafx.h"
#include <iostream>
#include<istream>
#include<fstream>
using namespace std;
#include"../Include/CHexGridCell.h"
#include <assert.h>
#include "../Include/Globals.h"
#include "../Include/CWideStringHelper.h"
#include "../Include/CTextureLoader.h"
#include"../Include/CApp.h"
#include "../Dependencies/JSON/nlohmann/json.hpp"





/* */


CVector3 CHexGridCell::ScalePoint(CVector3  Center, int numpoint, float cellsize, bool pointy)
{
	CVector3 point;
	if (pointy == true)
	{
		float angle = 60 * numpoint - 30;
		float angleR = angle * PI_OVER_180;
		point.Y = 0.0f;
		point.X = Center.X + cellsize * cos(angleR);
		point.Z = Center.Y + cellsize * sin(angleR);
		return point;
	}
	else 
	{
		float angle = 60 * numpoint ;
		float angleR = angle * PI_OVER_180;
		point.Y = 0.0f;
		point.X = Center.X + cellsize * cos(angleR);
		point.Z = Center.Y + cellsize * sin(angleR);
		return point;
	}
	
	return point;
}


