#include "../include/CQuadTree.h"
#include <vector>
CQuadTreeNode::CQuadTreeNode()
{
}
////////////////////
void CQuadTreeNode::Subdivide(std::vector<CHexGridCell>* HexTotalCells, int QuadTreeLimits)
{
	int triCount = 0;
	for (int i = 0; i < HexTotalCells->size(); ++i)
	{
		triCount += HexTotalCells->at[i]->getTriangleCount();
		{
			if (HexTotalCells->size() == 1 || triCount < QuadTreeLimits)
			{
				//copiar elementos
			}
			else
			{
				CVector3 Croners[4];
				AABB_2D childBounds[4];
				//Todo en 3
				for (int i = 0; i < 3;i++)
				{
					Croners[0].X /= 2;
					Croners[2].X /= 2;
					Croners[1].Z /= 2;
					Croners[2].Z /= 2;
				}
				SectorOne = new CQuadTreeNode();
				SectorOne->SetLimits(childBounds[0]);
				//same for all the other ones 
				std::vector<CHexGridCell>ChildCells[4];
				{
					for (int i = 0; i < HexTotalCells->size(); i++)
					{
						CHexGridCell cell = HexTotalCells->at(i);
						CVector3 Coners[4];
						if (childBounds[0].corners)
						{
							ChildCells->push_back(cell);
						}
						SectorOne->Subdivide(ChildCells, QuadTreeLimits);
					}
				}
			}
			
		}
	}
}

void CQuadTreeNode::Subdivide2(std::vector<std::vector<CHexGridCell>> HexTotalCells, int QuadTreeBounds, AABB_2D parentBounds)
{
	int triCount = 0;
	for (int i = 0; i < HexTotalCells.size(); ++i)
	{
		for (int j = 0; j < HexTotalCells[i].size(); j++)
		{
			//triCount += HexTotalCells[i][j];//GetTriangle
		}
		
	}
	if ((HexTotalCells.size() * HexTotalCells[0].size())== 1 || triCount < QuadTreeBounds)
	{
		
		DataCopy = HexTotalCells;

	}
	else
	{
		CVector3 Croners[4];
		AABB_2D childBounds[4];
		//Todo en 3
		for (int i = 0; i < 3; i++)
		{
			Croners[0].X /= 2;
			Croners[2].X /= 2;
			Croners[1].Z /= 2;
			Croners[2].Z /= 2;
			parentBounds.getCorners(Croners);
			Croners[1].X /= 2;
			Croners[3].X /= 2;
			Croners[2].Z /= 2;
			Croners[3].Z /= 2;
			childBounds[0].setCorners(Croners);

			parentBounds.getCorners(Croners);
			Croners[0].X /= 2;
			Croners[2].X /= 2;
			Croners[2].Z /= 2;
			Croners[3].Z /= 2;
			childBounds[1].setCorners(Croners);

			parentBounds.getCorners(Croners);
			Croners[1].X /= 2;
			Croners[3].X /= 2;
			Croners[0].Z /= 2;
			Croners[1].Z /= 2;
			childBounds[2].setCorners(Croners);

			parentBounds.getCorners(Croners);
			Croners[0].X /= 2;
			Croners[2].X /= 2;
			Croners[1].Z /= 2;
			Croners[0].Z /= 2;
			childBounds[3].setCorners(Croners);

	
		}
		SectorOne = new CQuadTreeNode();
		SectorOne->SetLimits(childBounds[0]);
		SectorTwo = new CQuadTreeNode();
		SectorTwo->SetLimits(childBounds[1]);
		SectorTree = new CQuadTreeNode();
		SectorTree->SetLimits(childBounds[2]);
		SectorFor = new CQuadTreeNode();
		SectorFor->SetLimits(childBounds[3]);

		//same for all the other ones 
		std::vector<CHexGridCell>ChildCells[4];
		{
			for (int i = 0; i < HexTotalCells.size(); i++)
			{
				for (int j = 0; j < HexTotalCells.size(); j++)
				{
					CHexGridCell cell = HexTotalCells[i][j];
					CVector3 Coners[4];
					if (childBounds[0].corners)
					{
						ChildCells->push_back(cell);
					}
					SectorOne->Subdivide(ChildCells, QuadTreeBounds);
				}
				
			}
		}
	}
}

void CQuadTreeNode::SetLimits(AABB_2D Limits)
{
	

}

CHexGridCell* CQuadTreeNode::render(std::vector<CHexGridCell>* HexTotalCells,CCamara*cam)
{
	CHexGridCell*lmao;
	if (cam->isAABBVisibile(m_Bounds))
	{
		SectorOne->render(HexTotalCells,cam);
		SectorTwo->render(HexTotalCells, cam);
		SectorTree->render(HexTotalCells, cam);
		SectorFor->render(HexTotalCells, cam);
	}
	return lmao;
}
