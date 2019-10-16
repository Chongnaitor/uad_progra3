#include "pch.h"
#define CREATING_DLL
#include "NewDLL.h"

int g_Result = 0;

int Add2Numbers(int a, int b)
{
	return a + b;
}