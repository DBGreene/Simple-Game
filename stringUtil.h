#pragma once

#include <string>

class StringUtils
{
public:
	int FindStr(std::string key, std::string str)
	{
		int index = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == key[0])
			{
				for (int x = 0; x < key.length(); x++)
				{
					if (str[i + x] == key[x])
					{
						index++;
						if (index == key.length())
						{
							return 1;
						}
					}
					else
					{
						index = 0;
					}
				}
			}
		}
		return 0;
	}
protected:
private:

};