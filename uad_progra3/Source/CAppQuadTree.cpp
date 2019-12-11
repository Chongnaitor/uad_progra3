#include"../Include/CAppQuadTree.h"


CAppQuadTree::CAppQuadTree():
CAppQuadTree(CGameWindow::DEFAULT_WINDOW_WIDTH,CGameWindow::DEFAULT_WINDOW_HEIGHT)
{
}
CAppQuadTree::CAppQuadTree(int window_width, int window_heith)
	:CApp(window_heith,window_heith),m_current_Delta_Time{0.0}, m_object_Rotation{ 0.0 }, m_object_Position{ -1.5f, 0.0f, 0.0f }, m_rotation_Speed{ DEFAULT_ROTATION_SPEED }, m_Hexa_Vertex_Array_Object{ 0 }, m_num_faces_hexa{ 0 }, m_render_Polygon_Mode{ 0 }
{
}
void CAppQuadTree::render()
{
	Arbolito.m_Root->render(getOpenGLRenderer(), m_colorModelShaderId);
}

void CAppQuadTree::run()
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

void CAppQuadTree::onMouseMove(float deltaX, float deltaY)
{
}

void CAppQuadTree::onF2(int mods)
{
}

void CAppQuadTree::onF3(int mods)
{
}



void CAppQuadTree::initialize()
{

	m_colorModelShaderId = getOpenGLRenderer()->getShaderProgramID(SHADER_PROGRAM_COLOR_OBJECT);

	if (m_colorModelShaderId == 0)
	{
		cout << "ERROR: Unable to load color shader" << endl;
		return;
	}
	m_grid = new CHexGrid();
	m_grid->m_CellSize = 4;
	m_grid->m_Columnas = 2;
	m_grid->m_Filas = 2;
	m_grid->Orientacion = "pointy";

	m_grid->FilasPorColumnas(getOpenGLRenderer(), m_color_Model_Shader_Id, true);
	m_grid->CreateGeometry(getOpenGLRenderer(), m_colorModelShaderId,true);
	int Cols = m_grid->m_Columnas;
	int Rows = m_grid->m_Filas;


	float MinX = 0.0f;
	float MaxX = 0.0f;
	float MinZ = 0.0f;
	float MaxZ = 0.0f;

	CVector3 Cell;
	for (int i = 0; i < Cols; i++)
	{
		for (int j = 0; j < Rows; j++)
		{
			Cell = m_grid->Centros[i][j];
			CHexGridCell CeldaCualquiera;
			//m_Cells.push_back(Cell);

			for (int k = 0; k < 6; k++)
			{
				CeldaCualquiera.m_objectPosition = Cell;

				//CVector3 Corner = Cell->getCorner(k); //falta implementar
				CVector3 Corner = CeldaCualquiera.ScalePoint(Cell, k, 1.0f, true);

				if (Corner.X < MinX)
				{
					MinX = Corner.X;
				}
				if (Corner.X > MaxX)
				{
					MaxX = Corner.X;
				}
				if (Corner.Z < MinZ)
				{
					MinZ = Corner.Z;
				}
				if (Corner.Z > MaxZ)
				{
					MaxZ = Corner.Z;
				}
			}
		}

	}

	CVector3 corners[4];
	corners[0].X = MinX;
	corners[0].Z = MinZ;
	corners[0].Y = 0.0f;

	corners[1].X = MaxX;
	corners[1].Z = MinZ;
	corners[1].Y = 0.0f;

	corners[2].X = MinX;
	corners[2].Z = MaxZ;
	corners[2].Y = 0.0f;

	corners[3].X = MaxX;
	corners[3].Z = MaxZ;
	corners[3].Y = 0.0f;
	AABB_2D BOX;
	BOX.setCorners(corners);

	Arbolito.Subdivide(m_grid->Centros, 6, BOX, 1);
	if (!Arbolito.m_Root->isRender(getOpenGLRenderer(), m_colorModelShaderId))
	{
		cout << "Valio verga la geometria del arbolito." << endl;
	}

}

void CAppQuadTree::onArrowUp(int mods)
{
	std::cout << "Arrow up\n";
}

void CAppQuadTree::onArrowDown(int mods)
{
	std::cout << "Arrow down\n";
}

void CAppQuadTree::onArrowLeft(int mods)
{
	std::cout << "Arrow left\n";
}

void CAppQuadTree::onArrowRight(int mods)
{
	std::cout << "Arrow right\n";
}


void CAppQuadTree::update(double P)
{


}





