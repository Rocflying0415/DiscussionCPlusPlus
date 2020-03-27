/*
 * main.cpp
 *
 *  Created on: 2020年3月27日
 *      Author: Zuokp
 */
#include <iostream>
#include <string>

char findFirstCharOnce(const std::string & str_);

int main(int argc, char *argv[])
{
	char cElem = '\0';
	std::string str("");

	std::cout << "Please input string:";
	getline(std::cin, str);
	cElem = findFirstCharOnce(str);
	if (cElem == '\0')
		std::cout << "No character is found in the string that appears only once." << std::endl;
	else
		std::cout << "The first character that appears only once is \'" \
			      << cElem << "\'." << std::endl;
	return 0;
}

char findFirstCharOnce(const std::string & str_)
{
	char cElem = '\0', cTemp = '\0';
	if (str_.empty())
		return cElem;
	size_t i;
	const size_t MAX_LENGTH = 256;
	const size_t ulStrLength = str_.length();
	int szFlag[MAX_LENGTH];

	for (i = 0; i < MAX_LENGTH; ++i)
		szFlag[i] = 0;
	for (i = 0; i < ulStrLength; ++i)
	{
		cTemp = str_[i];
		++szFlag[static_cast<int>(cTemp)];
	}
	for (i = 0; i < ulStrLength; ++i)
	{
		cTemp = str_[i];
		if (1 == szFlag[static_cast<int>(cTemp)])
		{
			cElem = cTemp;
			break;
		}
	}
	return cElem;
}


