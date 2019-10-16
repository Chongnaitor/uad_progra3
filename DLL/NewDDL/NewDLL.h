#pragma once
#ifdef CREATING_DLL   // DEFINIDO POR EL DESARROLLADOR

#define DLL_API extern "C" __declspec(dllexport)   //Compilar al crear la DLL

#else
#define DLL_API extern "C" __declspec(dllimport)   //Compilar al usar la DLL

#endif // CREATING_DLL  

DLL_API int g_Result;
DLL_API int Add2Numbers(int a, int b);
