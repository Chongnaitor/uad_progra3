
#include "../stdafx.h"
#include <iostream>
using namespace std;
#include"../Include/CHexGridCell.h"
#include <assert.h>
#include "../Include/Globals.h"
#include "../Include/CWideStringHelper.h"
#include "../Include/CTextureLoader.h"
#include"../Include/CApp.h"


CHexGridCell::CHexGridCell()
{
}

/* */
CHexGridCell::~CHexGridCell()
{
	cout << "Destructor: ~CHexGridCell()" << endl;

	// Free memory allocated in this class instance here
	// =================================================
	//
	if (m_textureID > 0)
	{
		getOpenGLRenderer()->deleteTexture(&m_textureID);
	}

	if( m_hexagonVertexArray > 0)
	{
		getOpenGLRenderer()->freeGraphicsMemoryForObject(&m_hexagonVertexArray);
	}
	// =================================================
}

CVector3 CHexGridCell::ScalePoint(CVector3& Center, int numpoint, float cellsize, bool pointy)
{
	CVector3 point;
	float angle = 60 * numpoint - 30;
	float angleR = angle * PI_OVER_180;
	point.Y = 0.0f;
	point.X = Center.X + cellsize * cos(angleR);
	point.Z = Center.Y + cellsize * sin(angleR);
	return point;
}

void CHexGridCell::CellGeometry()
{

	bool LetsDoThis = false;
	CVector3 Point_1;
	CVector3 Point_2;
	CVector3 Point_3;
	CVector3 Point_4;
	CVector3 Point_5;
	CVector3 Point_6;
	CVector3 Center{ 0, 0, 0 };
	Point_1 = ScalePoint(Center, 1, 3, false);
	Point_2 = ScalePoint(Center, 2, 3, false);
	Point_3 = ScalePoint(Center, 3, 3, false);
	Point_4 = ScalePoint(Center, 4, 3, false);
	Point_5 = ScalePoint(Center, 5, 3, false);
	Point_6 = ScalePoint(Center, 6, 3, false);
	float VertexArray[18] =
	{ Point_1.X,Point_1.Y,Point_1.Z,
	 Point_2.X,Point_2.Y,Point_2.Z,
	 Point_3.X,Point_3.Y,Point_3.Z,
	 Point_4.X,Point_4.Y,Point_4.Z,
	 Point_5.X,Point_5.Y,Point_5.Z,
	 Point_6.X,Point_6.Y,Point_6.Z
	};
	faces = 4;
	unsigned short indices[12] =
	{
		0,2,1,
		5,2,0,
		5,3,2,
		5,4,3
	};
	float vertexUVs[6] =
	{
		0.0f,0.0f,0.0f,0.0f,0.0f,0.0f
	};
	float normalData[12] = {
		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0

	};
	unsigned short faceNormalIndices[12] = {
		0, 0, 0,
		0, 0, 0,
		0, 0, 0
	};




	LetsDoThis = getOpenGLRenderer()->allocateGraphicsMemoryForObject(
		&m_colorModelShaderId,
		&m_hexagonVertexArray,
		VertexArray,
		6,        // Numero de vertices, internamente el codigo multiplica sizeof(float) * numVertices * 3
		normalData,
		6,
		vertexUVs,
		6,
		indices,
		4,        // Numero de indices, internamente el codigo multiplica sizeof(unsigned short) * numIndicesVert * 3
		faceNormalIndices,
		6,
		indices,
		6
	);

	if (!LetsDoThis)
	{
		faces = 0;

		if (m_hexagonVertexArray > 0)
		{
			getOpenGLRenderer()->freeGraphicsMemoryForObject(&m_hexagonVertexArray);
			m_hexagonVertexArray = 0;
		}
	}



	/*getOpenGLRenderer()->renderObject(
		&m_texturedModelShaderId,
		&m_pyramidVertexArrayObject,
		&m_textureID,
		m_numFacesPyramid,
		color,
		&modelMatrix2,
		COpenGLRenderer::EPRIMITIVE_MODE::TRIANGLES,
		false
	);*/
}


void CHexGridCell::initialize()
{
	// Initialize app-specific stuff here
	// ==================================
	//
	// Get shader for color objects
	// -------------------------------------------------------------------------------------------------------------

	m_colorModelShaderId = getOpenGLRenderer()->getShaderProgramID(SHADER_PROGRAM_COLOR_OBJECT);

	if (m_colorModelShaderId == 0)
	{
		cout << "ERROR: Unable to load color shader" << endl;
		return;
	}

	// Get shader for textured objects
	// -------------------------------------------------------------------------------------------------------------

	m_texturedModelShaderId = getOpenGLRenderer()->getShaderProgramID(SHADER_PROGRAM_TEXTURED_OBJECT);

	if (m_texturedModelShaderId == 0)
	{
		cout << "ERROR: Unable to load texture shader" << endl;
		return;
	}

	// Texture
	// Load texture file, create OpenGL Texture Object
	// -------------------------------------------------------------------------------------------------------------
	std::wstring wresourceFilenameTexture;
	std::string resourceFilenameTexture;

	// Check texture file exists for the textured cube
	if (!CWideStringHelper::GetResourceFullPath(MC_LEAVES_TEXTURE, wresourceFilenameTexture, resourceFilenameTexture))
	{
		cout << "ERROR: Unable to find one or more resources: " << endl;
		cout << "  " << MC_LEAVES_TEXTURE << endl;
		return;
	}

	// Initialize the texture
	m_textureID = 0;
	if (!CTextureLoader::loadTexture(resourceFilenameTexture.c_str(), &m_textureID, getOpenGLRenderer()))
	{
		cout << "ERROR: Unable load texture:" << endl;
		cout << "  " << MC_LEAVES_TEXTURE << endl;
		return;
	}

	m_initialized = true;
	//createPyramidGeometry();
	CellGeometry();
}


void CHexGridCell::render()
{
	CGameMenu* menu = getMenu();

	// If menu is active, render menu
	if (menu != NULL
		&& menu->isInitialized()
		&& menu->isActive())
	{
		//...
	}
	else // Otherwise, render app-specific stuff here...
	{
		// =================================
		//
		// White 
		// Colors are in the 0..1 range, if you want to use RGB, use (R/255, G/255, G/255)
		float color[3] = { 1.0f, 1.0f, 1.0f };
		unsigned int noTexture = 0;
		double totalDegreesRotatedRadians = m_objectRotation * 3.1459 / 180.0;
		// convert total degrees rotated to radians;

		// Get a matrix that has both the object rotation and translation
		MathHelper::Matrix4 modelMatrix = MathHelper::SimpleModelMatrixRotationTranslation((float)totalDegreesRotatedRadians, m_objectPosition);

		if (m_hexagonVertexArray > 0 && faces > 0)
		{
			CVector3 pos2 = m_objectPosition;
			pos2 += CVector3(3.0f, 0.0f, 0.0f);
			MathHelper::Matrix4 modelMatrix2 = MathHelper::SimpleModelMatrixRotationTranslation((float)totalDegreesRotatedRadians, pos2);

			// Render pyramid in the first position, using the color shader
			getOpenGLRenderer()->renderObject(
				&m_colorModelShaderId,
				&m_hexagonVertexArray,
				&noTexture,
				faces,
				color,
				&modelMatrix,
				COpenGLRenderer::EPRIMITIVE_MODE::TRIANGLES,
				false
			);

			// Render same pyramid (same vertex array object identifier), in a second position, but this time with a texture
			
		}

		// =================================
	}
}

