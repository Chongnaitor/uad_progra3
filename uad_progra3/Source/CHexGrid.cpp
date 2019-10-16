#include"../Include/CHexGrid.h"
#include<istream>
#include<fstream>

void CHexGrid::ReadJSON(std::string Name)
{
	char Token;
	std::ifstream File(Name);
	std::string lmao;
	nlohmann::json j;
	j = nlohmann::json::parse(File);
	for (const auto& HexGrid : j["HexGrid"])
	{
		if (HexGrid.find("numCols") != HexGrid.end())
		{
			for (const auto& NumCols : HexGrid["numCols"])
				{
				std::cout << NumCols["numCols"];
				}
		}
	}
		

	
}

CHexGrid::CHexGrid()
{
	std::cout << "Se creo";
}
