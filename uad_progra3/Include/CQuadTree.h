#pragma once
#include "CQuadTreeNode.h"
class CQuadTree {
public:
	CQuadTree();
	void Initialize();
	void AddData(CQuadTreeNode*&Data, int Dato);
	int m_SubDivisionLimit;
	CQuadTreeNode* m_Root;
	CHexGridCell* Render(CCamara* Cam);

};