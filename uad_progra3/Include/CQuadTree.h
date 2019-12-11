#pragma once
#include "CQuadTreeNode.h"

class CQuadTree {
public:
	CQuadTree();
	void Subdivide(std::vector<std::vector<CVector3>>Hexcells, int limittri,AABB_2D aabb, int maxlimit);
	CQuadTreeNode* m_Root = nullptr;
	int m_SubDivisionLimit;
	
	CHexGridCell* Render(CCamara* Cam);

};