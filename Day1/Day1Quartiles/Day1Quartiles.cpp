// Day1Quartiles.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
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

int readCount()
{
	int count = 0;
	scanf_s("%d", &count);
	return count;
}

void order(int* data, size_t count)
{
	for (size_t i = 0; i < count; i++)
	{
		for (size_t j = i; j < count; j++)
		{
			if (data[j] < data[i])
			{
				auto buf = data[j];
				data[j] = data[i];
				data[i] = buf;
			}
		}
	}
}

void print(int* median, size_t count) {

	printf("==========\n");
	for (size_t i = 0; i < count; i++) {
		printf("%d\n", median[i]);
	}
	printf("==========\n");
}
float getMedian(int* data, int count)
{
	print(data, count);
	auto top = data[count / 2];
	auto bottom = data[(count - 1) / 2];
	return ((float)bottom + top) / 2;
}
float* calculateQuartiles(size_t count, int* data) {
	auto q = new float[3];
	auto half = count / 2;
	q[0] = getMedian(data, half);
	q[1] = getMedian(data, count);
	q[2] = getMedian(&data[(count + 1) / 2], half);
	return q;
}

void quartiles() {
	size_t count = readCount();
	auto data = readData(count);
	order(data, count);
	auto q  = calculateQuartiles(count, data);
	printf("%d", q[0]);
	printf("%d", q[1]);
	printf("%d", q[2]);
	//calculateQuartiles(9, new int[9]{ 3, 7, 8, 5, 12, 14, 21, 13, 18 });
	//calculateQuartiles(10, new int[10]{ 3, 7, 8, 5, 12, 14, 21, 15, 18, 14 });
}

std::vector<int>* prepareData(int* items, int* counts, size_t count)
{	
	std::vector<int>* result = new std::vector<int>();
	for (size_t i = 0; i < count; i++) {
		for (size_t j = 0; j < counts[i]; j++) {
			result->push_back(items[i]);
		}
	}
	return result;
}
void ranges() {
	size_t count = readCount();
	auto items = readData(count);
	auto counts = readData(count);
	auto data = prepareData(items, counts, count);
	order(data->data(), data->size());
	auto q = calculateQuartiles(data->size(), data->data());
	printf("%.1f", q[2] - q[0]);
	//calculateQuartiles(9, new int[9]{ 3, 7, 8, 5, 12, 14, 21, 13, 18 });
	//calculateQuartiles(10, new int[10]{ 3, 7, 8, 5, 12, 14, 21, 15, 18, 14 });
}
int main()
{
	ranges();
	return 0;
}
