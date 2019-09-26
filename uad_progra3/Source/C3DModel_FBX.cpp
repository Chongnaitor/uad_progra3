#include "..\Include\C3DModel_FBX.h"

bool C3DModel_FBX::ParserFBX(const char* const Nombre, bool swatch)
{
	float Numero2;

	int Indice = 0;
	char* Token = nullptr;

	char* SiguienteToken = nullptr;
	char* SiguienteToken2 = nullptr;
	int Numero;
	int NumeroDeLinea = 0;
	char Delimitador = '\t';
	char SiguienteDelimitador= '*';
	bool LeerArchivo = true;
	
	ifstream Archivo;
	string BufferDeLinea;


	
	//m_CurretVertex, m_CurrentNormal, m_CurrentFace, m_currentUV_Index;
	

	
	
	Archivo.open(Nombre);

	while (!Archivo.eof()) 
	{
		getline(Archivo, BufferDeLinea); 
		
		Token = strtok_s((char*)BufferDeLinea.c_str(), " ", &SiguienteToken);//
		NumeroDeLinea++;

		if (Token != NULL)
		{
			
			if (0 == strcmp(Token, "Vertices:"))
			{
				BufferDeLinea = SiguienteToken;
				Token = strtok_s((char*)BufferDeLinea.c_str(), "*", &SiguienteToken);
				BufferDeLinea = Token;
				Token = strtok_s((char*)BufferDeLinea.c_str(), " ", &SiguienteToken);
				
				istringstream iss(Token);
				iss >> Numero;

				
				m_numVertices = Numero / 3;

				
				m_verticesRaw = new float[Numero];
				getline(Archivo, BufferDeLinea);
				NumeroDeLinea++;

				Token = strtok_s((char*)BufferDeLinea.c_str(), " ", &SiguienteToken);
				if (0 == strcmp(Token, "a:"))
				{
					while (Token != NULL)
					{
						Token = strtok_s(SiguienteToken, ",", &SiguienteToken2);

						if (Indice < Numero)
						{
							istringstream iss2(Token);
							iss2 >> Numero2;

							m_verticesRaw[Indice++] = Numero2;
						}
						
						if (*SiguienteToken2 == NULL)
						{
							getline(Archivo, BufferDeLinea);
							NumeroDeLinea++;
							if (BufferDeLinea=="} ")
							{
								break;
							}
							SiguienteToken2 = (char*)BufferDeLinea.c_str();
						}
						SiguienteToken = SiguienteToken2;
					}
					
					Indice = 0;
				}
			}

		
			else if (0 == strcmp(Token, "PolygonVertexIndex:"))
			{
				BufferDeLinea = SiguienteToken;
				Token = strtok_s((char*)BufferDeLinea.c_str(), "*", &SiguienteToken);
				BufferDeLinea = Token;
				Token = strtok_s((char*)BufferDeLinea.c_str(), " ", &SiguienteToken);
				istringstream iss(Token);
				iss >> Numero;

				m_numFaces = Numero / 3;
				m_vertexIndices = new unsigned short[Numero];

	
				getline(Archivo, BufferDeLinea);
				NumeroDeLinea++;

				Token = strtok_s((char*)BufferDeLinea.c_str(), " ", &SiguienteToken);
				if (0 == strcmp(Token, "a:"))
				{
					while (Token != NULL)
					{
						Token = strtok_s(SiguienteToken, ",", &SiguienteToken2);

						if (Indice < Numero)
						{
							
							istringstream iss2(Token);
							iss2 >> Numero2;
							if (Numero2 < 0)
							{
								Numero2=(Numero2 * -1) - 1;
							}
							m_vertexIndices[Indice++] = Numero2;
						}
						if (*SiguienteToken2 == NULL)
						{
							getline(Archivo, BufferDeLinea);
							NumeroDeLinea++;
							if (BufferDeLinea == "} ")
							{
								break;
							}
							SiguienteToken2 = (char*)BufferDeLinea.c_str();
						}
						SiguienteToken = SiguienteToken2;
						
					
					}
					Indice = 0;
				}
			}

			
			else if (0 == strcmp(Token, "Normals:"))
			{
				BufferDeLinea = SiguienteToken;
				Token = strtok_s((char*)BufferDeLinea.c_str(), "*", &SiguienteToken);
				BufferDeLinea = Token;
				Token = strtok_s((char*)BufferDeLinea.c_str(), " ", &SiguienteToken);
				
				istringstream iss(Token);
				iss >> Numero;

				m_numNormals = Numero / 3;
				m_normalsRaw =new  float [Numero];

				
				getline(Archivo, BufferDeLinea);
				NumeroDeLinea++;

				Token = strtok_s((char*)BufferDeLinea.c_str(), " ", &SiguienteToken);
				if (0 == strcmp(Token, "a:"))
				{
					while (Token != NULL)
					{
						Token = strtok_s(SiguienteToken, ",", &SiguienteToken2);

						

						if (Indice < Numero)
						{
							istringstream iss2(Token);
							iss2 >> Numero2;

							m_normalsRaw[Indice++] = Numero2;
						}
						if (*SiguienteToken2 == NULL)
						{
							getline(Archivo, BufferDeLinea);
							NumeroDeLinea++;
							if (BufferDeLinea == "} ")
							{
								break;
							}
							SiguienteToken2 = (char*)BufferDeLinea.c_str();
						}
						SiguienteToken = SiguienteToken2;
						

					
					}
					Indice = 0;
				}
			}

		
			else if (0 == strcmp(Token, "UV:"))
			{
				BufferDeLinea = SiguienteToken;
				Token = strtok_s((char*)BufferDeLinea.c_str(), "*", &SiguienteToken);
				BufferDeLinea = Token;
				Token = strtok_s((char*)BufferDeLinea.c_str(), " ", &SiguienteToken);
				
				istringstream iss(Token);
				iss >> Numero;

				m_numUVCoords = Numero / 2;
				m_uvCoordsRaw = new float[Numero];

			
				getline(Archivo, BufferDeLinea);
				NumeroDeLinea++;

				Token = strtok_s((char*)BufferDeLinea.c_str(), " ", &SiguienteToken);
				if (0 == strcmp(Token, "a:"))
				{
					while (Token != NULL)
					{
						Token = strtok_s(SiguienteToken, ",", &SiguienteToken2);

					

						if (Indice < Numero)
						{
							istringstream iss2(Token);
							iss2 >> Numero2;

							m_uvCoordsRaw[Indice++] = Numero2;
						}
						if (*SiguienteToken2 == NULL)
						{
							getline(Archivo, BufferDeLinea);
							NumeroDeLinea++;
							if (BufferDeLinea == "} ")
							{
								break;
							}
							SiguienteToken2 = (char*)BufferDeLinea.c_str();
						}
						SiguienteToken = SiguienteToken2;
						

					}	
					Indice = 0;
				}
			}
	
			else if (0 == strcmp(Token, "UVIndex:"))
			{
				BufferDeLinea = SiguienteToken;
				Token = strtok_s((char*)BufferDeLinea.c_str(), "*", &SiguienteToken);
				BufferDeLinea = Token;
				Token = strtok_s((char*)BufferDeLinea.c_str(), " ", &SiguienteToken);
			
				istringstream iss(Token);
				iss >> Numero;
				m_numFaces = Numero / 3;
				m_UVindices = new unsigned short[Numero];

				
				getline(Archivo, BufferDeLinea);
				NumeroDeLinea++;

				Token = strtok_s((char*)BufferDeLinea.c_str(), " ", &SiguienteToken);
				if (0 == strcmp(Token, "a:"))
				{
					while (Token != NULL)
					{
						Token = strtok_s(SiguienteToken, ",", &SiguienteToken2);

						

						if (Indice < Numero)
						{
							istringstream iss2(Token);
							iss2 >> Numero2;

						    m_UVindices[Indice++] = Numero2;
						}
						if (*SiguienteToken2 == NULL)
						{
							getline(Archivo, BufferDeLinea);
							NumeroDeLinea++;
							if (BufferDeLinea == "} ")
							{
								break;
							}
							SiguienteToken2 = (char*)BufferDeLinea.c_str();
						}
						
						SiguienteToken = SiguienteToken2;
					}
					

					Indice = 0;
				}
			}
		}

	}

	Archivo.close();

	
	std::cout << "lmao";

	
	return true;
}



void C3DModel_FBX::reset()
{
	if (m_vertexIndices != NULL)
	{
		cout << "deleting vertex indices" << endl;
		delete[] m_vertexIndices;
		m_vertexIndices = NULL;
	}
	if (m_normalIndices != NULL)
	{
		cout << "deleting normal indices" << endl;
		delete[] m_normalIndices;
		m_normalIndices = NULL;
	}
	if (m_UVindices != NULL)
	{
		cout << "deleting UV indices" << endl;
		delete[] m_UVindices;
		m_UVindices = NULL;
	}
	if (m_verticesRaw != NULL)
	{
		cout << "deleting vertices (float)" << endl;
		delete[] m_verticesRaw;
		m_verticesRaw = NULL;
	}
	if (m_normalsRaw != NULL)
	{
		cout << "deleting normals (float)" << endl;
		delete[] m_normalsRaw;
		m_normalsRaw = NULL;
	}
	if (m_uvCoordsRaw != NULL)
	{
		cout << "deleting uvCoords (float)" << endl;
		delete[] m_uvCoordsRaw;
		m_uvCoordsRaw = NULL;
	}
	if (m_modelTextureFilename != nullptr)
	{
		delete[] m_modelTextureFilename;
		m_modelTextureFilename = nullptr;
	}

	m_materialNames.clear();
	m_materialFilenames.clear();
	m_materialColors.clear();

	m_numVertices = 0;
	m_numNormals = 0;
	m_numUVCoords = 0;
	m_numFaces = 0;
	m_CurretVertex, m_CurrentNormal, m_CurrentFace, m_currentUV_Index, m_CurrentUV = 0;
	m_modelGeometryLoaded = false;

	m_graphicsMemoryObjectId = 0;
	m_shaderProgramId = 0;
	m_textureObjectId = 0;
	m_modelHasNormals = false;
	m_modelHasUVs = false;
	m_modelHasTextures = false;
}

bool C3DModel_FBX::loadFromFile(const char* const Nombre)

{
	bool readFileOk = false;

	// Free any previous resources
	reset();

	// First pass is to count the Numero of vertices, normals, UVs, faces
	readFileOk = ParserFBX(Nombre, true);

	// Display count
	cout << "Finished reading 3D model" << endl;
	cout << "Vertices: " << m_CurrentFace << endl;
	cout << "Normals: " << m_CurretVertex << endl;
	cout << "UVCoords: " << m_CurrentUV << endl;
	cout << "Faces: " << m_CurrentNormal << endl;

	if (readFileOk)
	{
		// Check for MAX Numero of faces
		if (m_numVertices >= 65535 || m_numNormals >= 65535 || m_numUVCoords >= 65535)
		{
			cout << "Error: object cannot have more than 65535 vertices" << endl;
			cout << "Object attempted to load has: " << m_numVertices << " vertices" << endl;
			return false;
		}

		// If model was read without normals or UVCoords, we'll set a default value for them
		// i.e.:
		//   0,0 for UV coords
		//   face normal for normal
		if (m_numNormals == 0)
		{
			m_modelHasNormals = false;
			m_numNormals = m_numVertices;
		}
		else
		{
			m_modelHasNormals = true;
		}

		if (m_numUVCoords == 0)
		{
			m_numUVCoords = m_numVertices;
			m_modelHasUVs = false;
		}
		else
		{
			m_modelHasUVs = true;
		}

		

		if (readFileOk)
		{
			m_modelGeometryLoaded = true;

			if (!m_modelHasNormals)
			{
				computeFaceNormals();
			}
		}
	}
	else
	{
		cout << "Error ocurred while reading 3D model." << endl;
	}

	return readFileOk;
}


C3DModel_FBX::C3DModel_FBX(): C3DModel(), m_CurretVertex(0), m_CurrentNormal(0), m_CurrentFace(0), m_currentUV_Index(0), m_CurrentUV(0)
{

}

C3DModel_FBX::~C3DModel_FBX()
{
	reset();
}
