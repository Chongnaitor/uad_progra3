// uad_progra3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#include "Include/CApp.h"
#include "Include/CAppCubeTest.h"
#include "Include/CAppObjLoader.h"
#include "Include/CAppGeometricFigures.h"
#include "Include/CAppEmpty.h"
#include "Include/CAppMyCube.h"
#include "Include/CApp_Toloide_esfera.h"
#include "Include/CAppFBXLoader.h"
int main()
{
	CAppGeometricFigures* lmao = new CAppGeometricFigures();
	lmao->run();

}

