#include "../Include/CAppHexGrid.h"
#include "../Include/CApp.h"
CAppHexGrid::CAppHexGrid():
 CAppHexGrid(CGameWindow::DEFAULT_WINDOW_WIDTH, CGameWindow::DEFAULT_WINDOW_HEIGHT)
{

}

CAppHexGrid::CAppHexGrid(int window_width, int window_heith)
{
}

CAppHexGrid::~CAppHexGrid()
{
	if (CHexGrid::m_TexturId > 0)
	{
		getOpenGLRenderer()->deleteTexture(&m_TexturId);

	}
	if (CHexGrid::Cell.m_hexagonVertexArray > 0)
	{

	}
}

void CAppHexGrid::render()
{
}

void CAppHexGrid::run()
{
}

void CAppHexGrid::onMouseMove(float deltaX, float deltaY)
{
}

void CAppHexGrid::onF2(int mods)
{
}

void CAppHexGrid::onF3(int mods)
{
}
