
#pragma once
#ifndef CHEXGRIDCELL_H
#define CHEXGRIDCELL_H

#include "../Include/Globals.h"
#include "../Include/CApp.h""

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
class CHexGridCell :CApp
{
private:

	bool m_initialized;

	// Variables used for controlling the rotation and object position
	// ---------------------------------------------------------------


	// Current object position
	CVector3 m_objectPosition;

	//  Object rotation speed (degrees per second)


	// Variables used for storing OpenGL identifiers
	// ---------------------------------------------------------------

	// OpenGL Shader Program for the color-only object
	unsigned int m_colorModelShaderId;

	// OpenGL Shader Program for the textured object
	unsigned int m_texturedModelShaderId;

	// An OpenGL Vertex Array Object is a reference to graphics memory that tells OpenGL where to look for the geometry of the object
	// It needs to be initialized using the allocateGraphicsMemory() method from the renderer.
	

	// Identifier for the OpenGL Texture Object 
	unsigned int m_textureID;

	// Other variables
	// ---------------------------------------------------------------

	int m_renderPolygonMode;
	unsigned int m_hexagonVertexArray;
	int faces;
	double m_objectRotation;
protected:

	// Method to initialize the menu 
	// (not needed here, so return false)
	

public:
	// Constructors and destructor
	CHexGridCell();
	~CHexGridCell();


	// --------------------------------------------------------------------------------------------------------------------------
	// Inherited methods from CApp
	// Initialize(), update(), run(), and render() are PURE VIRTUAL methods, so they need to be implemented in this DERIVED class
	// --------------------------------------------------------------------------------------------------------------------------
	CVector3 ScalePoint(CVector3& Center, int numpoint, float cellsize, bool pointy);
	void CellGeometry();
	// Method to initialize any objects for this class
	void initialize();

	// Method to update any objecs based on time elapsed since last frame


	// Method to render the app
	void render();

	

};

#endif // !CAPPGEOMETRICFIGURES_H