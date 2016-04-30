#include "levelReader.h"

#include <fstream>
#include "stringUtil.h"
#include <iostream>

LevelReader::LevelReader()
{
}


LevelReader::~LevelReader()
{
}

std::vector<std::string> LevelReader::ReadFile(std::string loc)
{
	std::string line;
	std::ifstream gameFile;
	std::vector<std::string> locations;

	gameFile.open(loc);

	int index = 0;

	StringUtils util;

	std::getline(gameFile, line);
	if (line == "LEVEL")
	{
		index++;
		std::getline(gameFile, line);
		if (line == "{")
		{
			std::getline(gameFile, line);
			if (util.FindStr("LEFT_EXIT", line) && index == 1)
			{
				std::getline(gameFile, line);
				if (util.FindStr("{", line))
				{
					std::getline(gameFile, line);
					if (util.FindStr("location:", line))
					{
						std::cout << line << std::endl;
						std::string finStr;
						for (int i = 0; i < line.length(); i++)
						{
							if (i > 10)
							{
								finStr += line[i];
							}
						}
						locations.push_back(finStr);
						std::getline(gameFile, line);
						if (util.FindStr("data:", line))
						{
							finStr = "";
							for (int i = 0; i < line.length(); i++)
							{
								if (i > 6)
								{
									finStr += line[i];
								}
							}
							locations.push_back(finStr);
							std::getline(gameFile, line);
							if (util.FindStr("}", line))
							{
								index++;
								std::getline(gameFile, line);
							}
						}
					}
				}
			}
		}
	}
	if (util.FindStr("RIGHT_EXIT", line) && index == 2)
	{
		std::getline(gameFile, line);
		if (util.FindStr("{", line))
		{
			std::getline(gameFile, line);
			if (util.FindStr("location:", line))
			{
				std::cout << line << std::endl;
				std::string finStr;
				for (int i = 0; i < line.length(); i++)
				{
					if (i > 10)
					{
						finStr += line[i];
					}
				}
				locations.push_back(finStr);
				std::getline(gameFile, line);
				if (util.FindStr("data:", line))
				{
					finStr = "";
					for (int i = 0; i < line.length(); i++)
					{
						if (i > 6)
						{
							finStr += line[i];
						}
					}
					locations.push_back(finStr);
					std::getline(gameFile, line);
					if (util.FindStr("}", line))
					{
						index++;
						std::getline(gameFile, line);
					}
				}
			}
		}
	}
	if (util.FindStr("TOP_EXIT", line) && index == 3)
	{
		std::getline(gameFile, line);
		if (util.FindStr("{", line))
		{
			std::getline(gameFile, line);
			if (util.FindStr("location:", line))
			{
				std::cout << line << std::endl;
				std::string finStr;
				for (int i = 0; i < line.length(); i++)
				{
					if (i > 10)
					{
						finStr += line[i];
					}
				}
				locations.push_back(finStr);
				std::getline(gameFile, line);
				if (util.FindStr("data:", line))
				{
					finStr = "";
					for (int i = 0; i < line.length(); i++)
					{
						if (i > 6)
						{
							finStr += line[i];
						}
					}
					locations.push_back(finStr);
					std::getline(gameFile, line);
					if (util.FindStr("}", line))
					{
						index++;
						std::getline(gameFile, line);
					}
				}
			}
		}
	}
	if (util.FindStr("BOTTOM_EXIT", line) && index == 4)
	{
		std::getline(gameFile, line);
		if (util.FindStr("{", line))
		{
			std::getline(gameFile, line);
			if (util.FindStr("location:", line))
			{
				std::cout << line << std::endl;
				std::string finStr;
				for (int i = 0; i < line.length(); i++)
				{
					if (i > 10)
					{
						finStr += line[i];
					}
				}
				locations.push_back(finStr);
				std::getline(gameFile, line);
				if (util.FindStr("data:", line))
				{
					finStr = "";
					for (int i = 0; i < line.length(); i++)
					{
						if (i > 6)
						{
							finStr += line[i];
						}
					}
					locations.push_back(finStr);
					std::getline(gameFile, line);
					if (util.FindStr("}", line))
					{
						index++;
					}
				}
			}
		}
	}

	gameFile.close();
	return locations;
}
