#pragma once
#include "CApp.h"
#include "CQuadTreeNode.h"
#include "CQuadTree.h"
#include "CHexGridCell.h"
#include "CAppHexGrid.h"
class CAppQuadTree :public CApp
{
public:
	CAppQuadTree();
	CAppQuadTree(int window_width, int window_heith);
	CHexGrid* m_grid=nullptr;
	void Iniatilize();

	CQuadTree Arbolito;

	void onArrowUp(int mods);
    void onArrowDown(int mods);
    void onArrowLeft(int mods);
	void onArrowRight(int mods);
	
	void render();
	void run();
	void onMouseMove(float deltaX, float deltaY);
	void onF2(int mods);
	void onF3(int mods);
	bool Pointy=true;
	bool m_initialized=false;

	int m_num_faces_hexa=0;
	unsigned int m_renderPolygonMode=0;
	int m_render_Polygon_Mode=0;

	double m_rotation_Speed=0;

	double m_object_Rotation=0;

	double m_current_Delta_Time=0;

	CVector3 m_object_Position{0,0,0};

	unsigned int m_texture_ID=0;

	unsigned int m_color_Model_Shader_Id=0;

	unsigned int m_textured_Model_Shader_Id=0;

	unsigned int m_Hexa_Vertex_Array_Object=0;

	unsigned int m_colorModelShaderId=0;
	unsigned int m_texturedModelShaderId=0;
	unsigned int m_textureID=0;

	void initialize();
	bool initializeMenu() { return false; };
	void update(double P);
};							