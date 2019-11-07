#pragma once
#include "CCamera.h"
#include "CHexGridCell.h"
class CQuadTreeNode {
	CQuadTreeNode();
	void Subdivide();
	CHexGridCell* render(CCamara* cam);

};