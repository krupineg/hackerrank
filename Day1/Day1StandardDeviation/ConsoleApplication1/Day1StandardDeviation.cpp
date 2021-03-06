// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iterator>
#include <vector>
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

long long sum(int* data, size_t count) 
{
	long long sum = 0;
	for (size_t i = 0; i < count; i++)
	{
		sum += data[i];
	}
	return sum;
}

int readCount()
{
	int count = 0;
	scanf_s("%d", &count);
	return count;
}

void print(int* median, size_t count) {

	printf("==========\n");
	for (size_t i = 0; i < count; i++) {
		printf("%d\n", median[i]);
	}
	printf("==========\n");
}

int main()
{
	auto count = readCount();
	auto data = readData(count);
	auto mean = sum(data, count) / count;
	double divident = 0;
	for (size_t i = 0; i < count; i++) 
	{
		auto distance = data[i] - mean;
		divident += distance * distance;
	}
	auto deviation = sqrt(divident / count);
	printf("%.1f", deviation);
    return 0;
}

