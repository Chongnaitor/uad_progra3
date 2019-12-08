#pragma once
#include "CApp.h"
#include "CQuadTreeNode.h"
#include "CQuadTree.h"
#include "CHexGridCell.h"
#include "CAppHexGrid.h"
class CAppQuadTree : CApp
{
	CAppHexGrid* m_grid;
	void Iniatilize();

	void onArrowUp(int mods);
    void onArrowDown(int mods);
    void onArrowLeft(int mods);
	void onArrowRight(int mods);
	void onF2(int mods) {}
	void onF3(int mods) {}
	void onF4(int mods) {}
	void onF5(int mods) {}
	void onF6(int mods) {}
	void onF7(int mods) {}
	void onF8(int mods) {}
	void onF9(int mods) {}
	void onF10(int mods) {}
	void onF11(int mods) {}
	void onMouseMove(float deltaX, float deltaY) {}

	void initialize(){}
	void update(double delta_time){}
	void run() {}
	void render() {}


	bool initializeMenu() { return true; }
};							