#pragma once
#include "../Dependencies/JSON/nlohmann/json.hpp"
#include <string>
#include <iostream>
#include <vector>
#include "CVector3.h"
#include "CApp.h"
#include "Globals.h"
#include "CTextureLoader.h"
#include "CWideStringHelper.h"
#include "CHexGridCell.h"
class CHexGrid :public CApp
{
public:
	CHexGrid();
	void render();
	CHexGridCell Cell;
	int m_Columnas;
	int m_Filas;
	unsigned int m_TexturId;
	int m_CellSize;
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
	void initialize();
	
	


};