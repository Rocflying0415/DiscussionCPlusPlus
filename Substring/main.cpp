/*
 * main.cpp
 *
 *  Created on: 2020年3月26日
 *      Author: Zuokp
 */
#include <iostream>
#include <string>

void findLongestSubstring(const std::string &str_, std::string &strLongest_);

int main(int argc, char *argv[])
{
	std::string str("");
	std::string strLongest("");

	std::cout << "Please input string:";
	getline(std::cin, str);
	findLongestSubstring(str, strLongest);
	std::cout << "The longest continuous substring of a string is \"" << strLongest << "\"." << std::endl;

	return 0;
}

void findLongestSubstring(const std::string &str_, std::string &strLongest_)
{
	if (str_.empty())
		return;
	char cElem;
	size_t i, j;
	size_t ulSubStrLength;
	const size_t ulStrLength = str_.length();
	std::string strTemp;

	if (!strLongest_.empty())
		strLongest_.clear();
	for (i = 0; i < ulStrLength; )
	{
		cElem = str_[i];
		for (j = i + 1; j < ulStrLength; )
		{
			if (cElem != str_[j])
				break;
			++j;
		}
		ulSubStrLength = j - i;
		if (ulSubStrLength > strLongest_.length())
			strLongest_ = str_.substr(i, ulSubStrLength);
		else
		{
			if (ulSubStrLength == strLongest_.length())
			{
				strTemp = str_.substr(i, ulSubStrLength);
				if (strTemp.compare(strLongest_) < 0)
					strLongest_ = strTemp;
			}
		}
		i += ulSubStrLength;
	}
}


