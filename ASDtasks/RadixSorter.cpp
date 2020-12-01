#include "RadixSorter.h"

vector<long> RadixSorter::sort(vector<long> arr)
{
	long arrSize = arr.size();
	vector<long> result = arr;
	vector<long> subArr;
	long max = arr[0];
	for (long i = 0; i < arrSize; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	int numOfDigets = 0;
	while (max != 0)
	{
		max /= 10;
		numOfDigets++;
	}

	for (int i = 1; i <= numOfDigets; i++)
	{
		int n1 = 1;
		int n2 = 1;
		for (int j = 0; j < i; j++)
		{
			n1 *= 10;
		}
		for (int j = 0; j < i-1; j++)
		{
			n2 *= 10;
		}

		map<int, long> digitsCounter = {
			{0,0},
			{1,0},
			{2,0},
			{3,0},
			{4,0},
			{5,0},
			{6,0},
			{7,0},
			{8,0},
			{9,0}
		};

		for (int j = 0; j < arrSize; j++)
		{
			int dig = (result[j] % n1) / n2;
			digitsCounter[dig]++;
		}
		for (int j = 0; j < 10; j++)
		{
			for (long k = 0; k < arrSize; k++)
			{
				int dig = (result[k] % n1) / n2;
				if (dig == j)
				{
					subArr.push_back(result[k]);
					digitsCounter[j]--;
				}
				if (digitsCounter[j] == 0) break;
			}
		}
		result = subArr;
		subArr.erase(subArr.begin(), subArr.end());
	}
	return result;
}
