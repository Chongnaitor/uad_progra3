// uad_progra3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#include "Include/CApp.h"
#include"Include/CHexGrid.h"

int main()
{
	CHexGrid lmao;
	lmao.ReadJSON("Resources/MEDIA/HEXGRID/hexgrid_cfg.json");

	return 0;
}

