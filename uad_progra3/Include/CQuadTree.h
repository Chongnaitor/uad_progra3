#pragma once
#include "CQuadTreeNode.h"

class CQuadTree {
public:
	CQuadTree();
	void Subdivide(std::vector<CHexGridCell>* HexTotalCells, AABB_2D aabb);
	CQuadTreeNode* m_Root;
	int m_SubDivisionLimit;

	CHexGridCell* Render(CCamara* Cam);

};