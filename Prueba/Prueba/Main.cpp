#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	char* token = nullptr;
	char* nextToken = nullptr;
	char *nextToken2 = nullptr;
	char delimiterToken = '\t';
	char nextdelimiterToken = '*';
	bool read_file = true;
	int number;
	int line_number = 0;

	float *Array_Vert = nullptr;
	float *Array_Face = nullptr;
	float *Array_Normal = nullptr;
	float *Array_UV = nullptr;
	float *Array_Face_UV = nullptr;


	float Number2;

	int Index = 0;

	int NumVertice;
	int	NumNormal;
	int NumUV;
	int NumFace;
	int NumFaceUV;
	//int NumFaceNormal;

	ifstream in_file;
	string line_buffer;

	//Abrimos el archivo
	in_file.open("Test_Cube_Ascii.fbx");

	while (!in_file.eof()) //minentras no se acabe el arcivo seguimos leyendo
	{
		getline(in_file, line_buffer); //le damos a line_buffer el valor de la linea actual

		line_number++; //aumentamos la linea

		token = strtok_s((char *)line_buffer.c_str(), " ", &nextToken);//se le da un valor a token y nextTokend

		if (token != NULL)
		{
			//*Vertices*//
			if (0 == strcmp(token, "Vertices:"))
			{
				line_buffer = nextToken;
				token = strtok_s((char *)line_buffer.c_str(), "*", &nextToken);
				line_buffer = token;
				token = strtok_s((char *)line_buffer.c_str(), " ", &nextToken);
				//aqui token te da la cantidad de datos de los vertices
				//aqui se transforma token en int para darle tamaño al arreglo
				istringstream iss (token);
				iss >> number;

				//Numero total de vertices
				NumVertice = number / 3;

				//se crea un array del numero total de vertices
				Array_Vert = new float[number];
				getline(in_file, line_buffer);
				line_number++;
				
				token = strtok_s((char *)line_buffer.c_str(), " ", &nextToken);
				if (0 == strcmp(token, "a:"))
				{
					while (token != NULL)
					{
						token = strtok_s(nextToken, ",", &nextToken2);
						
						//agregar el dato a la lista
						if (Index < number)
						{
							istringstream iss2(token);
							iss2 >> Number2;

							Array_Vert[Index++] = Number2;
						}
						//aqui va la lista de lo que se va ha guardar
						nextToken = nextToken2;
					}
					//se resetea el index
					Index = 0;
				}
			}

			//*Faces*//
			else if (0 == strcmp(token, "PolygonVertexIndex:"))
			{
				line_buffer = nextToken;
				token = strtok_s((char *)line_buffer.c_str(), "*", &nextToken);
				line_buffer = token;
				token = strtok_s((char *)line_buffer.c_str(), " ", &nextToken);
				//aqui token te da la cantidad de datos de los vertices
				//aqui se transforma token en int para darle tamaño al arreglo
				istringstream iss(token);
				iss >> number;

				NumFace = number / 3;

				Array_Face = new float[number]; //se crea array con el numero total de caras
				getline(in_file, line_buffer);
				line_number++;

				token = strtok_s((char *)line_buffer.c_str(), " ", &nextToken);
				if (0 == strcmp(token, "a:"))
				{
					while (token != NULL)
					{
						token = strtok_s(nextToken, ",", &nextToken2);
						
						//agregar el dato a la lista

						if (Index < number)
						{
							istringstream iss2(token);
							iss2 >> Number2;

							Array_Face[Index++] = Number2;
						}

						//aqui va la lista de lo que se va ha guardar
						nextToken = nextToken2;
					}
					Index = 0;
				}
			}

			//*Normal*//
			else if (0 == strcmp(token, "Normals:"))
			{
				line_buffer = nextToken;
				token = strtok_s((char *)line_buffer.c_str(), "*", &nextToken);
				line_buffer = token;
				token = strtok_s((char *)line_buffer.c_str(), " ", &nextToken);
				//aqui token te da la cantidad de datos de los vertices
				//aqui se transforma token en int para darle tamaño al arreglo
				istringstream iss(token);
				iss >> number;

				NumNormal = number / 3;

				Array_Normal = new float[number];
				getline(in_file, line_buffer);
				line_number++;

				token = strtok_s((char *)line_buffer.c_str(), " ", &nextToken);
				if (0 == strcmp(token, "a:"))
				{
					while (token != NULL)
					{
						token = strtok_s(nextToken, ",", &nextToken2);
						
						//agregar el dato a la lista

						if (Index < number)
						{
							istringstream iss2(token);
							iss2 >> Number2;

							Array_Normal[Index++] = Number2;
						}

						//aqui va la lista de lo que se va ha guardar
						nextToken = nextToken2;
					}
					Index = 0;
				}
			}

			//*UV*//
			else if (0 == strcmp(token, "UV:"))
			{
				line_buffer = nextToken;
				token = strtok_s((char *)line_buffer.c_str(), "*", &nextToken);
				line_buffer = token;
				token = strtok_s((char *)line_buffer.c_str(), " ", &nextToken);
				//aqui token te da la cantidad de datos de los vertices
				//aqui se transforma token en int para darle tamaño al arreglo
				istringstream iss(token);
				iss >> number;

				NumUV = number / 3;

				Array_UV = new float[number];
				getline(in_file, line_buffer);
				line_number++;

				token = strtok_s((char *)line_buffer.c_str(), " ", &nextToken);
				if (0 == strcmp(token, "a:"))
				{
					while (token != NULL)
					{
						token = strtok_s(nextToken, ",", &nextToken2);
						
						//agregar el dato a la lista

						if (Index < number)
						{
							istringstream iss2(token);
							iss2 >> Number2;

							Array_UV[Index++] = Number2;
						}

						//aqui va la lista de lo que se va ha guardar
						nextToken = nextToken2;
					}
					Index = 0;
				}
			}
			//*FaceUV*//
			else if (0 == strcmp(token, "UVIndex:"))
			{
				line_buffer = nextToken;

				token = strtok_s((char *)line_buffer.c_str(), "*", &nextToken);
				line_buffer = token;
				token = strtok_s((char *)line_buffer.c_str(), " ", &nextToken);
				//aqui token te da la cantidad de datos de los vertices


				//aqui se transforma token en int para darle tamaño al arreglo
				istringstream iss(token);
				iss >> number;


				NumFaceUV = number / 3;

				Array_Face_UV = new float[number];
				getline(in_file, line_buffer);
				line_number++;

				token = strtok_s((char *)line_buffer.c_str(), " ", &nextToken);
				if (0 == strcmp(token, "a:"))
				{
					while (token != NULL)
					{
						token = strtok_s(nextToken, ",", &nextToken2);
					
						//agregar el dato a la lista

						if (Index < number)
						{
							istringstream iss2(token);
							iss2 >> Number2;

							Array_Face_UV[Index++] = Number2;
						}

						//aqui va la lista de lo que se va ha guardar
						nextToken = nextToken2;
					}
					Index = 0;
				}
			}
		}

	}

	in_file.close();
	/*if (token != nullptr)
	{
		delete token;
	}
	if (nextToken != nullptr)
	{
		delete nextToken;
	}*/

	delete[] Array_Vert;
	delete[] Array_Face;
	delete[] Array_Face_UV;
	delete[] Array_Normal;
	delete[] Array_UV;
	return 0;
}
