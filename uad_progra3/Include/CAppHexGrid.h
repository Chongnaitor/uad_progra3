#pragma once
#include"CHexGrid.h"
#include "CHexGridCell.h"

struct CAppHexGrid : public CHexGrid
{
public:
	CAppHexGrid();
	CAppHexGrid(int window_width, int window_heith);
	~CAppHexGrid();
	void render();
	void run();
	void onMouseMove(float deltaX, float deltaY);
	void onF2(int mods);
	void onF3(int mods);




};
