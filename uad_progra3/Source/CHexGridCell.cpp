
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



CHexGridCell::CHexGridCell()
{
}

/* */
CHexGridCell::~CHexGridCell()
{
	
	// =================================================
}

CVector3 CHexGridCell::ScalePoint(CVector3& Center, int numpoint, float cellsize, bool pointy)
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

void CHexGridCell::CellGeometry(bool Pointy)
{

	bool LetsDoThis = false;
	CVector3 Point_1;
	CVector3 Point_2;
	CVector3 Point_3;
	CVector3 Point_4;
	CVector3 Point_5;
	CVector3 Point_6;
	CVector3 Center{ 0, 0, 0 };
	if (Pointy == true)
	{
		Point_1 = ScalePoint(Center, 1, 3, true);
		Point_2 = ScalePoint(Center, 2, 3, true);
		Point_3 = ScalePoint(Center, 3, 3, true);
		Point_4 = ScalePoint(Center, 4, 3, true);
		Point_5 = ScalePoint(Center, 5, 3, true);
		Point_6 = ScalePoint(Center, 6, 3, true);
	}
	else
	{
		Point_1 = ScalePoint(Center, 1, 3, false);
		Point_2 = ScalePoint(Center, 2, 3, false);
		Point_3 = ScalePoint(Center, 3, 3, false);
		Point_4 = ScalePoint(Center, 4, 3, false);
		Point_5 = ScalePoint(Center, 5, 3, false);
		Point_6 = ScalePoint(Center, 6, 3, false);
	}

	float VertexArray[18] =
	{ Point_1.X,Point_1.Y,Point_1.Z,
	 Point_2.X,Point_2.Y,Point_2.Z,
	 Point_3.X,Point_3.Y,Point_3.Z,
	 Point_4.X,Point_4.Y,Point_4.Z,
	 Point_5.X,Point_5.Y,Point_5.Z,
	 Point_6.X,Point_6.Y,Point_6.Z
	};
	faces = 4;
	unsigned short indices[12] =
	{
		0,2,1,
		5,2,0,
		5,3,2,
		5,4,3
	};
	float vertexUVs[6] =
	{
		0.0f,0.0f,0.0f,0.0f,0.0f,0.0f
	};
	float normalData[12] = {
		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0

	};
	unsigned short faceNormalIndices[12] = {
		0, 0, 0,
		0, 0, 0,
		0, 0, 0
	};




	LetsDoThis = getOpenGLRenderer()->allocateGraphicsMemoryForObject(
		&m_colorModelShaderId,
		&m_hexagonVertexArray,
		VertexArray,
		6,        // Numero de vertices, internamente el codigo multiplica sizeof(float) * numVertices * 3
		normalData,
		6,
		vertexUVs,
		6,
		indices,
		4,        // Numero de indices, internamente el codigo multiplica sizeof(unsigned short) * numIndicesVert * 3
		faceNormalIndices,
		6,
		indices,
		6
	);

	if (!LetsDoThis)
	{
		faces = 0;

		if (m_hexagonVertexArray > 0)
		{
			getOpenGLRenderer()->freeGraphicsMemoryForObject(&m_hexagonVertexArray);
			m_hexagonVertexArray = 0;
		}
	}


}




