#pragma once
#ifndef  C3DMODEL_FBX
#define C3DMODEL_FBX


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#include "CVector3.h"
#include "COpenGLRenderer.h"
#include "C3DModel.h"


class C3DModel_FBX : public C3DModel
{

                                        
private:
	int m_CurretVertex, m_CurrentNormal, m_CurrentFace, m_currentUV_Index,m_CurrentUV;
	bool ParserFBX(const char* const NombreDeArchivo, bool Tknext);
	
protected:
	void reset();
	bool loadFromFile(const char* const NombreDeArchivo);

public:
	C3DModel_FBX();
	~C3DModel_FBX();

	

};


#endif //  C3DMODEL_FBX