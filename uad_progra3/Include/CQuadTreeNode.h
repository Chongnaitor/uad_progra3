#pragma once
#include "CCamera.h"
#include "CHexGridCell.h"
#include<vector>
class CQuadTreeNode {
public:
	CQuadTreeNode();
	void Subdivide();
	CHexGridCell* render(CCamara* cam);
	std::vector<CHexGridCell>HexTotalCells;
	CQuadTreeNode* SectorOne=nullptr;
	CQuadTreeNode* SectorTwo=nullptr;
	CQuadTreeNode* SectorTree=nullptr;
	CQuadTreeNode* SectorFor=nullptr;
};