
#pragma once
#ifndef CHEXGRIDCELL_H
#define CHEXGRIDCELL_H

#include "../Include/Globals.h"
#include "../Include/CApp.h""
#include"../Include/COpenGLRenderer.h"

/* ******************************************************************************************************************************************
* This class shows an example of how to manually allocate GRAPHICS memory for a 3D object.
* The object is rendered twice, one with colors only, and one with a texture.
* Each of these ways of rendering an object needs a different shader.
* Displaying more than one of those objects in screen can be achieved by making two render calls, using different positions, but
* using the same graphics memory reference of the cube.
* ******************************************************************************************************************************************/

// --------------------------------------------------------------------------------------------------------------------------------------
// Class that inherits from Base class CApp
// Base class CApp has members for: CGameWindow, CGameMenu, and COpenGLRenderer, which we can access through the public/protected methods
// --------------------------------------------------------------------------------------------------------------------------------------
struct CHexGridCell 
{


	
	// Variables used for controlling the rotation and object position
	// ---------------------------------------------------------------


	// Current object position
	CVector3 m_objectPosition;

	
	CVector3 ScalePoint(CVector3 Center, int numpoint, float cellsize, bool pointy);
	
	void Assignvalues(float size, bool ispointy);

	int GetTrinagles();
	float Tamaño=0.0f;
	bool Pointy;

};

#endif // !CAPPGEOMETRICFIGURES_H