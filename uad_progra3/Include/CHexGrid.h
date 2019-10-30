#pragma once
#include "../Dependencies/JSON/nlohmann/json.hpp"
#include <string>
#include <iostream>
#include <vector>
#include "CVector3.h"
#include "Globals.h"
#include "CTextureLoader.h"
#include "CWideStringHelper.h"
#include "CHexGridCell.h"
#include"../Include/COpenGLRenderer.h"
#include <vector>
class CHexGrid 
{
public:
	CHexGrid();
	CHexGridCell Cell;
	int m_Columnas;
	int m_Filas;
	unsigned int m_TexturId;
	float m_CellSize;
	int m_NumofHexas=m_Columnas*m_Filas;
	unsigned int m_ColorShaderID;
	unsigned int m_texturedModelShaderId;
	unsigned int m_colorModelShaderId;
	std::string Orientacion;
	void ReadJSON(std::string Name);
	bool m_initialized;
	double m_currentDeltaTime;
	double m_objectRotation;
	CVector3 m_objectPosition;
	double m_rotationSpeed;
	void CreateGeometry(COpenGLRenderer *const Lmao, unsigned int m_colorModelShaderId, bool Pointy);
	void FilasPorColumnas(COpenGLRenderer* const Lmao, unsigned int m_colorModelShaderId, bool Pointy);
	unsigned int m_colorModelSaderId;
	unsigned int m_textureID;
	int m_renderPolygonMode;
	unsigned int m_hexagonVertexArray;
	int faces;
	std::vector<std::vector<CVector3>>Centros;
	
	
	


};