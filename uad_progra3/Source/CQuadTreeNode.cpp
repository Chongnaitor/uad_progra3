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
		//triCount += HexTotalCells->at[i]->getTriangleCount();
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
						if (childBounds[0].m_points)
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
