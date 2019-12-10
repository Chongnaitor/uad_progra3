#pragma once
#include "CCamera.h"
#include "AABB_2D.h"
#include "CHexGridCell.h"
#include<vector>
class CQuadTreeNode {
public:
	CQuadTreeNode();
	void Subdivide(std::vector<CHexGridCell>* HexTotalCells, int QuadTreeBounds);
	void Subdivide2(std::vector<std::vector<CHexGridCell>> HexTotalCells, int QuadTreeBounds, AABB_2D parentBounds);
	void SetLimits(AABB_2D Limits);
	AABB_2D m_Bounds;
	std::vector<std::vector<CHexGridCell>>DataCopy;
	CHexGridCell* render(std::vector<CHexGridCell>* HexTotalCells,CCamara*cam);
	std::vector<CHexGridCell>*HexTotalCells;
	CQuadTreeNode* SectorOne=nullptr;
	CQuadTreeNode* SectorTwo=nullptr;
	CQuadTreeNode* SectorTree=nullptr;
	CQuadTreeNode* SectorFor=nullptr;
};