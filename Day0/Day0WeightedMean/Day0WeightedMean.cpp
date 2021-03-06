// Day0WeightedMean.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

static int readCount()
{
	int count = 0;
	scanf_s("%d", &count);
	return count;
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

static float calculate(int count, int* data, int* weight)
{
	auto divident = 0;
	auto divider = 0;
	for (size_t i = 0; i < count; i++) {
		auto item = data[i];
		auto w = weight[i];
		divident += item * w;
		divider += w;
	}
	return (float)divident / divider;
}

int main()
{
	auto count = readCount();
	auto data = readData(count);
	auto weight = readData(count);
	auto result = calculate(count, data, weight);
	printf("%.1f", result);
    return 0;
}

