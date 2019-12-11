#include "../include/CQuadTree.h"
#include <vector>
CQuadTreeNode::CQuadTreeNode()
{
}
////////////////////
void CQuadTreeNode::Subdivide(std::vector<CVector3*> HexTotalCells,  int QuadTreeLimits,AABB_2D Lmao, int currlimit, int maxlimit)
{
	int triCount = 0;
	for (int i = 0; i < HexTotalCells.size(); ++i)
	{
		triCount += 4;
	}
	if (HexTotalCells.size() == 1 || triCount < QuadTreeLimits || currlimit >= maxlimit)
	{
		//copiar elementos
		HexTotalCellsB = HexTotalCells;
	}
	else
	{
		CVector3 Croners[4];
		AABB_2D childBounds[4];
		//Todo en 3
			Lmao.getCorners(Croners);
			Croners[1].X = (Croners[1].getX() / 2)+  (Croners[0].getX() / 2);
			Croners[3].X = (Croners[3].getX() / 2) + (Croners[0].getX() / 2);
			Croners[2].Z = (Croners[2].getZ() / 2) + (Croners[0].getX() / 2);
			Croners[3].Z = (Croners[3].getZ() / 2) + (Croners[0].getX() / 2);
			childBounds[0].setCorners(Croners);
			Lmao.getCorners(Croners);
			Croners[0].X = (Croners[0].getX() / 2) + (Croners[1].getX() / 2);
			Croners[2].X = (Croners[2].getX() / 2) + (Croners[1].getX() / 2);
			Croners[2].Z = (Croners[2].getZ() / 2) + (Croners[1].getX() / 2);
			Croners[3].Z = (Croners[3].getZ() / 2) + (Croners[1].getX() / 2);
			childBounds[1].setCorners(Croners);

			Lmao.getCorners(Croners);
			Croners[1].X = (Croners[1].getX() / 2) + (Croners[2].getX() / 2);
			Croners[3].X = (Croners[3].getX() / 2) + (Croners[2].getX() / 2);
			Croners[0].Z = (Croners[0].getZ() / 2) + (Croners[2].getX() / 2);
			Croners[1].Z = (Croners[1].getZ() / 2) + (Croners[2].getX() / 2);
			childBounds[2].setCorners(Croners);

			Lmao.getCorners(Croners);
			Croners[0].X = (Croners[0].getX() / 2) + (Croners[3].getX() / 2);
			Croners[2].X = (Croners[2].getX() / 2) + (Croners[3].getX() / 2);
			Croners[1].Z = (Croners[1].getZ() / 2) + (Croners[3].getX() / 2);
			Croners[0].Z = (Croners[0].getZ() / 2) + (Croners[3].getX() / 2);
			childBounds[3].setCorners(Croners);
		SectorOne = new CQuadTreeNode();
		SectorOne->SetLimits(childBounds[0]);
		//same for all the other ones 
		std::vector<CVector3*>ChildCells[4];
		for (int i = 0; i < HexTotalCells.size(); i++)
		{
			CHexGridCell CualquierCelda;
			CVector3* cell = HexTotalCells[i];
			CualquierCelda.m_objectPosition = *cell;
			CVector3 Coners[6];
			for (int k = 1; k < 7; k++)
			{
				Coners[k] = CualquierCelda.ScalePoint(CualquierCelda.m_objectPosition, k, 1.0f, true);
			}
			if (childBounds[0].pointsInside(Coners))
			{
				ChildCells->push_back(cell);
			}
			if (childBounds[1].pointsInside(Coners))
			{
					ChildCells->push_back(cell);
			}
			if (childBounds[2].pointsInside(Coners))
			{
				ChildCells->push_back(cell);
			}
			if (childBounds[3].pointsInside(Coners))
			{
				ChildCells->push_back(cell);
			}
		}
		SectorOne->Subdivide(ChildCells[0], QuadTreeLimits,childBounds[0], currlimit + 1, maxlimit);
		SectorTwo->Subdivide(ChildCells[1], QuadTreeLimits,childBounds[1], currlimit + 1, maxlimit);
		SectorTree->Subdivide(ChildCells[2], QuadTreeLimits,childBounds[2], currlimit + 1, maxlimit);
		SectorFor->Subdivide(ChildCells[3], QuadTreeLimits,childBounds[3], currlimit + 1, maxlimit);
	}
}

void CQuadTreeNode::Subdivide2(std::vector<std::vector<CVector3>> HexTotalCells, int QuadTreeBounds, AABB_2D parentBounds, int currlimit, int maxlimit)
{
	int triCount = 0;
	for (int i = 0; i < HexTotalCells.size(); ++i)
	{
		for (int j = 0; j < HexTotalCells[i].size(); j++)
		{
			triCount += 4;
		}
		
	}
	if ((HexTotalCells.size() * HexTotalCells[0].size())== 1 || triCount < QuadTreeBounds || currlimit >= maxlimit)
	{
		
		DataCopy = HexTotalCells;

	}
	else
	{
		CVector3 Croners[4];
		AABB_2D childBounds[4];
		//Todo en 3

			parentBounds.getCorners(Croners);
			Croners[1].X = (Croners[1].getX() / 2)+  (Croners[0].getX() / 2);
			Croners[3].X = (Croners[3].getX() / 2) + (Croners[0].getX() / 2);
			Croners[2].Z = (Croners[2].getZ() / 2) + (Croners[0].getX() / 2);
			Croners[3].Z = (Croners[3].getZ() / 2) + (Croners[0].getX() / 2);
			childBounds[0].setCorners(Croners);
			parentBounds.getCorners(Croners);
			Croners[0].X = (Croners[0].getX() / 2) + (Croners[1].getX() / 2);
			Croners[2].X = (Croners[2].getX() / 2) + (Croners[1].getX() / 2);
			Croners[2].Z = (Croners[2].getZ() / 2) + (Croners[1].getX() / 2);
			Croners[3].Z = (Croners[3].getZ() / 2) + (Croners[1].getX() / 2);
			childBounds[1].setCorners(Croners);

			parentBounds.getCorners(Croners);
			Croners[1].X = (Croners[1].getX() / 2) + (Croners[2].getX() / 2);
			Croners[3].X = (Croners[3].getX() / 2) + (Croners[2].getX() / 2);
			Croners[0].Z = (Croners[0].getZ() / 2) + (Croners[2].getX() / 2);
			Croners[1].Z = (Croners[1].getZ() / 2) + (Croners[2].getX() / 2);
			childBounds[2].setCorners(Croners);

			parentBounds.getCorners(Croners);
			Croners[0].X = (Croners[0].getX() / 2) + (Croners[3].getX() / 2);
			Croners[2].X = (Croners[2].getX() / 2) + (Croners[3].getX() / 2);
			Croners[1].Z = (Croners[1].getZ() / 2) + (Croners[3].getX() / 2);
			Croners[0].Z = (Croners[0].getZ() / 2) + (Croners[3].getX() / 2);
			childBounds[3].setCorners(Croners);

			
	
			int counter = 0;
		SectorOne = new CQuadTreeNode();
		SectorOne->SetLimits(childBounds[0]);
		SectorTwo = new CQuadTreeNode();
		SectorTwo->SetLimits(childBounds[1]);
		SectorTree = new CQuadTreeNode();
		SectorTree->SetLimits(childBounds[2]);
		SectorFor = new CQuadTreeNode();
		SectorFor->SetLimits(childBounds[3]);

		CVector3 *Coners[6];
		CVector3* cell;
		CHexGridCell CeldaCualquiera;
		//same for all the other ones 
		std::vector<CVector3 *>ChildCells[4];
			for (int i = 0; i < HexTotalCells.size(); i++)
			{
				for (int j = 0; j < HexTotalCells[i].size(); j++)
				{
					
					cell = &HexTotalCells[i][j];
					CeldaCualquiera.m_objectPosition = *cell;
				
					for (int x = 1; x < 7; x++)
					{
						*Coners[x] = CeldaCualquiera.ScalePoint(CeldaCualquiera.m_objectPosition, x, 1.0f, true);
					}
					if (childBounds[0].pointsInside(*Coners))
					{
						ChildCells[0].push_back(cell);
					}
					if (childBounds[1].pointsInside(*Coners))
					{
						ChildCells[1].push_back(cell);
					}
					if (childBounds[2].pointsInside(*Coners))
					{
						ChildCells[2].push_back(cell);
					}
					if (childBounds[3].pointsInside(*Coners))
					{
						ChildCells[3].push_back(cell);
					}
					//some ifs
				}
				counter++;
				cout << counter << endl;
			}
			SectorOne->Subdivide(ChildCells[0], QuadTreeBounds, childBounds[0], currlimit + 1, maxlimit);
			SectorTwo->Subdivide(ChildCells[1],QuadTreeBounds,childBounds[1], currlimit + 1, maxlimit);
			SectorTree->Subdivide(ChildCells[2],QuadTreeBounds,childBounds[2], currlimit + 1, maxlimit);
			SectorFor->Subdivide(ChildCells[3],QuadTreeBounds,childBounds[3], currlimit + 1, maxlimit);
	}
}

void CQuadTreeNode::SetLimits(AABB_2D Limits)
{
	m_Bounds = Limits;

	Vertices[0] = m_Bounds.corners[0].getX();
	Vertices[1] = m_Bounds.corners[0].getY();
	Vertices[2] = m_Bounds.corners[0].getZ();

	Vertices[3] = m_Bounds.corners[1].getX();
	Vertices[4] = m_Bounds.corners[1].getY();
	Vertices[5] = m_Bounds.corners[1].getZ();


	Vertices[6] = m_Bounds.corners[2].getX();
	Vertices[7] = m_Bounds.corners[2].getY();
	Vertices[8] = m_Bounds.corners[2].getZ();


	Vertices[9] = m_Bounds.corners[3].getX();
	Vertices[10] = m_Bounds.corners[3].getY();
	Vertices[11] = m_Bounds.corners[3].getZ();

	Index[0] = 0;
	Index[1] = 1;
	Index[2] = 2;

	Index[3] = 1;
	Index[4] = 3;
	Index[5] = 2;

}			 

void CQuadTreeNode::render(COpenGLRenderer* Puntero, unsigned int ModelShad)
{
	float Color[3] = { 0,0.3,0 };
	MathHelper::Matrix4 M;
	CVector3 MatrixPos(0, 0, 0);
	M = MathHelper::SimpleModelMatrixRotationTranslation(0.0f, MatrixPos);
	Puntero->renderObject(&ModelShad, &VertexArray, 0, 2, Color, &M, COpenGLRenderer::EPRIMITIVE_MODE::TRIANGLES);
	if (SectorOne != nullptr && SectorTwo != nullptr && SectorTree != nullptr && SectorFor != nullptr)
	{
		SectorOne->render(Puntero, ModelShad);
		SectorTwo->render(Puntero, ModelShad);
		SectorTree->render(Puntero, ModelShad);
		SectorFor->render(Puntero,ModelShad);
	}
}

bool CQuadTreeNode::isRender(COpenGLRenderer* PumteroJr, unsigned int Lmao)
{
	bool esamadre;
	esamadre = PumteroJr->allocateGraphicsMemoryForObject(&Lmao, &VertexArray, Vertices, 4, Normal, 2, UV, 4, Index, 2, NormalIndex, 2, Index, 2);
	if (!esamadre)
	{
		PumteroJr->freeGraphicsMemoryForObject(&VertexArray);
	}
	return esamadre;
}
