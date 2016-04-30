#pragma once

#include <string>
#include <iostream>

void fatalError(std::string error)
{
	std::cout << "FatalError: " << error << std::endl;
	std::cout << "Press enter to continue..";
	int tmp;
	std::cin >> tmp;
	exit(1);
}