#include"../Include/CHexGrid.h"
#include<istream>
#include<fstream>
#include "../Include/CApp.h"


void CHexGrid::initialize()
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
	m_TexturId = 0;
	if (!CTextureLoader::loadTexture(resourceFilenameTexture.c_str(), &m_TexturId, getOpenGLRenderer()))
	{
		cout << "ERROR: Unable load texture:" << endl;
		cout << "  " << MC_LEAVES_TEXTURE << endl;
		return;
	}

	m_initialized = true;
	//createPyramidGeometry();
	Cell.CellGeometry(true);
}




CHexGrid::CHexGrid()
{
	std::cout << "Se creo"<<std::endl;
}
 void CHexGrid::ReadJSON(std::string Name)
{

	char Token;
	std::ifstream File(Name);
	std::string lmao;
	nlohmann::json j;
	j = nlohmann::json::parse(File);

	m_Columnas = j["HexGrid"]["numCols"];
	m_Filas = j["HexGrid"]["numRows"];
	m_CellSize = j["HexGrid"]["cellSize"];
	Orientacion = j["HexGrid"]["orientation"];



}