#pragma once

#include <string>
#include <vector>

class LevelReader
{
public:
	LevelReader();
	~LevelReader();

	std::vector<std::string> ReadFile(std::string loc);
protected:
private:
};

