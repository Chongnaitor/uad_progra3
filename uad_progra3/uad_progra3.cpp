// uad_progra3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Dependencies/JSON/nlohmann/json.hpp"
#include <iostream>
#include <fstream>
#include<../CAppHexGrid.h>
#include<../CAppGeometricFigures.h>
#include<../CAppQuadTree.h>

int main()
{
	CAppQuadTree * mApp = new CAppQuadTree();
	mApp->run();
	delete mApp;
	return 0;
}

//C:\Users\Chong\Documents\Cuarto Cuatrimestre\Programacion III\uad_progra3\Resources\MEDIA\HEXGRID