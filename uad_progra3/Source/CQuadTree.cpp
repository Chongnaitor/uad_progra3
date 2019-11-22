#include"../Include/CQuadTree.h"
#include"../Include/CQuadTreeNode.h"
#include <iostream>

void CQuadTree::Initialize()
{
	int data = 4;
	
	if (m_Root==nullptr)
	{
		AddData(m_Root,data);
	}
	else
	{
		if (m_Root->SectorOne==nullptr)
		{

		}

	}
}
void CQuadTree::AddData(CQuadTreeNode*&Data,int Dato)
{
	if (m_Root == nullptr)
	{
		m_Root->ExampleValue = Dato;

	}
	else
	{
		Data->ExampleValue = Dato;
	}
}