// MeanMedianModeCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <unordered_map>
#include <vector>
#include <iostream>

static std::vector<float> calculate(int* inputArray, size_t count)
{
	int maxCount = 0;
	int mod = 0;
	int medTop = 0;
	int medBottom = 0;
	int sum = 0;

	std::unordered_map<int, int> dict;

	for (size_t i = 0; i < count; i++)
	{
		for (size_t j = i; j < count; j++)
		{
			if (inputArray[j] < inputArray[i])
			{
				auto buf = inputArray[j];
				inputArray[j] = inputArray[i];
				inputArray[i] = buf;
			}
		}
		sum += inputArray[i];
		auto index = (i + 1) / 2;
		auto indexTop = i / 2;
		medBottom = inputArray[index];
		medTop = inputArray[indexTop];
		
		auto val = dict[inputArray[i]] + 1;
		dict[inputArray[i]] = val;
		if (val > maxCount)
		{
			mod = inputArray[i];
			maxCount = val;
		}
	}
	return std::vector<float> { (float)sum / count, (float)(medTop + medBottom) / 2, (float)mod };
}

static int* readData(int count)
{	
	int i;
	int* inputArray = new int[count];
	for (i = 0; i < count; i++)
	{
		int number;
		scanf_s("%d", &number);
		inputArray[i] = number;
	}
	return inputArray;
}

int readCount()
{
	int count = 0;
	scanf_s("%d", &count);
	return count;
}

int main()
{
	auto count = readCount();
	auto inputArray = readData(count);
	if (count >= 10 && count <= 2500) {
		auto result = calculate(inputArray, count);

		for (size_t i = 0; i < result.size(); i++)
		{
			printf("%.1f \n", result.at(i));
		}
	}

    return 0;
}