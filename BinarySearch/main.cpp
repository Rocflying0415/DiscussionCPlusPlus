/*
 * main.cpp
 *
 *  Created on: 2020年3月20日
 *      Author: Zuokp
 */
#include <iostream>

int  BinarySearch(const int* pData, const int length, const int value);

int main(int argc, char* argv[])
{
	const int szData[] = {-8, -5, 0, 1, 3, 4, 9, 23};
	int index = -1;
	int length = sizeof(szData) / sizeof(szData[0]);

	index = BinarySearch(szData, length, 24);

	std::cout << "index: " << index << std::endl;
	return 0;
}

int  BinarySearch(const int* pData, const int length, const int value)
{
	if (nullptr == pData || length < 1)
		return -1;
	int low = 0;
	int high = length - 1;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (value < pData[mid])
			high = mid -1;
		else if (value > pData[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

