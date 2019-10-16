#pragma once
#include "../Dependencies/JSON/nlohmann/json.hpp"
#include <string>
#include <iostream>
#include <vector>
class CHexGrid {
public:
	void ReadJSON(std::string Name);
	CHexGrid();
private:
	std::vector<std::string>lmao;

};