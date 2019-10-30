#include"../Include/CHexGrid.h"
#include<istream>
#include<fstream>
#include"../Include/CHexGridCell.h"



void CHexGrid::CreateGeometry(COpenGLRenderer* const Lmao, unsigned int m_colorModelShaderId,bool Pointy)
{
	CHexGridCell C;
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
		Point_1 = C.ScalePoint(Center, 1, m_CellSize, true);
		Point_2 = C.ScalePoint(Center, 2, m_CellSize, true);
		Point_3 = C.ScalePoint(Center, 3, m_CellSize, true);
		Point_4 = C.ScalePoint(Center, 4, m_CellSize, true);
		Point_5 = C.ScalePoint(Center, 5, m_CellSize, true);
		Point_6 = C.ScalePoint(Center, 6, m_CellSize, true);
	}
	else
	{
		Point_1 = C.ScalePoint(Center, 1, m_CellSize, false);
		Point_2 = C.ScalePoint(Center, 2, m_CellSize, false);
		Point_3 = C.ScalePoint(Center, 3, m_CellSize, false);
		Point_4 = C.ScalePoint(Center, 4, m_CellSize, false);
		Point_5 = C.ScalePoint(Center, 5, m_CellSize, false);
		Point_6 = C.ScalePoint(Center, 6, m_CellSize, false);
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




	LetsDoThis = Lmao->allocateGraphicsMemoryForObject(
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
			Lmao->freeGraphicsMemoryForObject(&m_hexagonVertexArray);
			m_hexagonVertexArray = 0;
		}
	}
}

void CHexGrid::FilasPorColumnas(COpenGLRenderer* const Lmao, unsigned int m_colorModelShaderId, bool Pointy)
{
	float Width=(sqrt(3)*m_CellSize);
	float Heihgt = (2 * m_CellSize);
	CVector3 PosicionInicial(0.0f,0.0f,0.0f);
	CreateGeometry(Lmao,m_colorModelShaderId,Pointy);
	for (int i = 0; i < m_Filas; i++)
	{
		std::vector<CVector3>Temp;

		for (int j = 0; j < m_Columnas; j++)
		{

			Temp.push_back(PosicionInicial);
		
			PosicionInicial.X = PosicionInicial.X + Width;
		}
		
		Centros.push_back(Temp);
		if (i % 2)
		{
			PosicionInicial.X = 0.0f;
		}
		else
		{
			PosicionInicial.X =  Width / 2;
		}
		PosicionInicial.Z += Heihgt * (0.75f);
	}


		 

}




CHexGrid::CHexGrid()
{
	std::cout << "Se creo"<<std::endl;
}
