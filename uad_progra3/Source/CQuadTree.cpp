#include"../Include/CQuadTree.h"
#include"../Include/CQuadTreeNode.h"
#include <iostream>

void CQuadTree::Subdivide(std::vector<CHexGridCell>* HexTotalCells, AABB_2D aabb)
{


		if (m_Root == nullptr)
		{
			m_Root = new CQuadTreeNode();
			m_Root->SetLimits(aabb);
			m_Root->Subdivide(HexTotalCells, m_SubDivisionLimit,aabb);
		}
	

}

CHexGridCell* CQuadTree::Render(CCamara* Cam)
{
	return nullptr;
}
