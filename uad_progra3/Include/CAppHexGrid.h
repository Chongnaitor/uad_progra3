#pragma once
#include"CHexGrid.h"
#include "CHexGridCell.h"
#include "CApp.h"
#include <string>
struct CAppHexGrid : public CApp
{
public:
	CAppHexGrid();
	CAppHexGrid(int window_width, int window_heith);
	~CAppHexGrid();
	CHexGrid  m_Grid;
	void render();
	void run();
	void onMouseMove(float deltaX, float deltaY);
	void onF2(int mods);
	void onF3(int mods);
	bool Pointy;
	bool m_initialized;

	int m_num_faces_hexa;
	unsigned int m_renderPolygonMode;
	int m_render_Polygon_Mode;

	double m_rotation_Speed;

	double m_object_Rotation;

	double m_current_Delta_Time;

	CVector3 m_object_Position;

	unsigned int m_texture_ID;

	unsigned int m_color_Model_Shader_Id;

	unsigned int m_textured_Model_Shader_Id;

	unsigned int m_Hexa_Vertex_Array_Object;

	unsigned int m_colorModelShaderId;
	unsigned int m_texturedModelShaderId;
	unsigned int m_textureID;
	
	void initialize();
	bool initializeMenu() { return false; };
	void update(double P);

};
