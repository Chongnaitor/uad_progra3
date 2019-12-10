#pragma once
#include "CCamera.h"
#include "AABB_2D.h"
#include "CHexGridCell.h"
#include<vector>
#include"COpenGLRenderer.h"
class CQuadTreeNode {
public:
	CQuadTreeNode();
	void Subdivide(std::vector<CHexGridCell*> HexTotalCells, int TriLimit, AABB_2D QuadTreeBounds);
	void Subdivide2(std::vector<std::vector<CHexGridCell>> HexTotalCells, int QuadTreeBounds, AABB_2D parentBounds);
	void SetLimits(AABB_2D Limits);
	AABB_2D m_Bounds;
	std::vector<std::vector<CHexGridCell>>DataCopy;
	void render(COpenGLRenderer*Puntero, unsigned int ModelShad);
	std::vector<CHexGridCell*>HexTotalCellsB;
	CQuadTreeNode* SectorOne=nullptr;
	CQuadTreeNode* SectorTwo=nullptr;
	CQuadTreeNode* SectorTree=nullptr;
	CQuadTreeNode* SectorFor=nullptr;
	unsigned int VertexArray;
	bool isRender(COpenGLRenderer*PumteroJr,unsigned int Lmao);
	float Vertices[12];
	unsigned short Index[6];
	float Normal[6] = { 0 };
	unsigned short NormalIndex[6] = { 0 };
	float UV[4] = { 0 };
};