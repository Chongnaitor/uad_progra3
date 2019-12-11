#include"../Include/CQuadTree.h"
#include"../Include/CQuadTreeNode.h"
#include <iostream>

CQuadTree::CQuadTree()
{
}

void CQuadTree::Subdivide(std::vector<std::vector<CVector3>>Hexcells, int limittri, AABB_2D aabb, int maxlimit)
{


		if (m_Root == nullptr)
		{
			m_Root = new CQuadTreeNode();
			m_Root->SetLimits(aabb);
			m_Root->Subdivide2(Hexcells, limittri, aabb, 0, maxlimit);
		}
	

}

CHexGridCell* CQuadTree::Render(CCamara* Cam)
{
	return nullptr;
}
