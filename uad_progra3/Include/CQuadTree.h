#pragma once
#include "CQuadTreeNode.h"
class CQuadTree {
private:
	int m_SubDivisionLimit;
	CQuadTreeNode* m_Root;
	CHexGridCell* Render(CCamara* Cam);

};