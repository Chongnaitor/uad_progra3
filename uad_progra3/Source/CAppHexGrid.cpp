#include "../Include/CAppHexGrid.h"
#include "../Include/CApp.h"
#include <fstream>


CAppHexGrid::CAppHexGrid():
 CAppHexGrid(CGameWindow::DEFAULT_WINDOW_WIDTH, CGameWindow::DEFAULT_WINDOW_HEIGHT)
{}



CAppHexGrid::CAppHexGrid(int window_width, int window_heith)
	: CApp(window_width, window_heith), m_current_Delta_Time{ 0.0 }, m_object_Rotation{ 0.0 }, m_object_Position{ -1.5f, 0.0f, 0.0f }, m_rotation_Speed{ DEFAULT_ROTATION_SPEED }, m_Hexa_Vertex_Array_Object{ 0 }, m_num_faces_hexa{ 0 }, m_render_Polygon_Mode{ 0 }
{

}

CAppHexGrid::~CAppHexGrid()
{
	
}
void CAppHexGrid::initialize()
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

	std::string NombreArchivo = "hexgrid_cfg.json";
	std::ifstream Archivo;
	Archivo.open(NombreArchivo);
	nlohmann::json j;
	 j = nlohmann::json::parse(Archivo);
	int Filas = j["HexGrid"]["numCols"];
    int Columnas =j["HexGrid"]["numRows"];
    float Cellsize = j["HexGrid"]["cellSize"];
	  m_Grid.m_Filas=Filas;
	  m_Grid.m_Columnas=Columnas;
	  m_Grid.m_CellSize=Cellsize;
	 std::string PonintyA= j["HexGrid"]["orientation"];
	 if (PonintyA == "pointy")
	 {
		 Pointy = true;
	 }
	 else
	 {
		 Pointy = false;
	 }

	 m_Grid.FilasPorColumnas(getOpenGLRenderer(),m_colorModelShaderId,Pointy);


}

void CAppHexGrid::update(double P)
{
	if(P <= 0.0f)
	{
		return;
	}
	double degreesToRotate = 0.0;

	m_current_Delta_Time = P;

	degreesToRotate = m_rotation_Speed * (P / 1000.0);

	m_object_Rotation += degreesToRotate;

	while (m_object_Rotation > 360.0)
	{
		m_object_Rotation -= 360.0;
	}
	if (m_object_Rotation < 0.0)
	{
		m_object_Rotation = 0.0;
	}
}
void CAppHexGrid::render()
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
		

		// Get a matrix that has both the object rotation and translation
		
		if (m_Grid.m_hexagonVertexArray > 0 && m_Grid.faces > 0)
		{
			for (int j=0;j<m_Grid.m_Filas;j++)
			{
				for (int i = 0; i<m_Grid.m_Columnas; i++)
				{
					if (m_Grid.Orientacion == "pointy") 
					{

				        
				        MathHelper::Matrix4 modelMatrix2 = MathHelper::SimpleModelMatrixRotationTranslation(0, m_Grid.Centros[j][i]*0.1f);
				        
				        // Render pyramid in the first position, using the color shader
				        getOpenGLRenderer()->renderObject(
				        	&m_colorModelShaderId,
				        	&m_Grid.m_hexagonVertexArray,
				        	&noTexture,
				        	m_Grid.faces,
				        	color,
				        	&modelMatrix2,
				        	COpenGLRenderer::EPRIMITIVE_MODE::TRIANGLES,
				        	false);
					}
					else
					{
						MathHelper::Matrix4 modelMatrix2 = MathHelper::SimpleModelMatrixRotationTranslation(0, m_Grid.Centros[i][j]*0.5f);

						// Render pyramid in the first position, using the color shader
						getOpenGLRenderer()->renderObject(
							&m_colorModelShaderId,
							&m_Grid.m_hexagonVertexArray,
							&noTexture,
							m_Grid.faces,
							color,
							&modelMatrix2,
							COpenGLRenderer::EPRIMITIVE_MODE::TRIANGLES,
							false);
					}
				}
			}
	
		}

		// =================================
	}

}

void CAppHexGrid::run()
{


	// Check if CGameWindow object AND Graphics API specific Window library have been initialized
	if (canRun())
	{
		// Create the Window 
		if (getGameWindow()->create(CAPP_PROGRA3_GEOMETRIC_WINDOW_TITLE))
		{
			// ALWAYS call initialize AFTER creating the window
			initialize();

			// Set initial clear screen color
			getOpenGLRenderer()->setClearScreenColor(0.25f, 0.0f, 0.75f);

			if (m_initialized)
			{
				getOpenGLRenderer()->setWireframePolygonMode();

				// Enter main loop
				cout << "Entering Main loop" << endl;
				getGameWindow()->mainLoop(this);
			}
		}
	}


}

void CAppHexGrid::onMouseMove(float deltaX, float deltaY)
{
	if (deltaX < 100.0f && deltaY < 100.0f)
	{
		float moveX = -deltaX * DEFAULT_CAMERA_MOVE_SPEED;
		float moveZ = -deltaY * DEFAULT_CAMERA_MOVE_SPEED;

		float currPos[3];
		for (int i = 0; i < m_Grid.m_Filas; i++)
		{
			for (int j = 0; j < m_Grid.m_Columnas; j++)
			{
				m_Grid.Centros[i][j].getValues(currPos);
				currPos[0] += moveX;
				currPos[2] += moveZ;
				m_Grid.Centros[i][j].setValues(currPos);
			}
		}
	}

}

void CAppHexGrid::onF2(int mods)
{
}

void CAppHexGrid::onF3(int mods)
{
	if (m_renderPolygonMode == 0)
	{
		getOpenGLRenderer()->setFillPolygonMode();
		m_renderPolygonMode = 1;
	}
	else
	{
		getOpenGLRenderer()->setWireframePolygonMode();
		m_renderPolygonMode = 0;
	}
}


