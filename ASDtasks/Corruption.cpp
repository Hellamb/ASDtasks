#include "Corruption.h"
#include "CountingSorter.h"

double Corruption::func(vector<double>& arr, double commission)
{
	CountingSorter cs;
	vector<double> newArr = cs.sort(arr);

	while (newArr.size() > 1)
	{
		double newAccountMoney = ((newArr[0] + newArr[1]) - (newArr[0] + newArr[1]) * commission);
		newArr.erase(newArr.begin(), newArr.begin() + 2);
		if (newArr.size() == 0) return newAccountMoney;

		if (newAccountMoney <= newArr[0])
		{
			newArr.insert(newArr.begin(), newAccountMoney);
		}
		else if (newAccountMoney >= newArr[newArr.size() - 1])
		{
			newArr.insert(newArr.end(), newAccountMoney);
		}
		else
		{
			int i = 0;
			int j = newArr.size() - 1;
			while (true)
			{
				int k = (i + j) / 2;
				if (newArr[k] == newAccountMoney)
				{
					newArr.insert(newArr.begin() + k, newAccountMoney);
					break;
				}
				else if (newArr[k] > newAccountMoney)
				{
					j = k;
				}
				else if (newArr[k] < newAccountMoney)
				{
					i = k;
				}
				if (j - i == 1)
				{
					newArr.insert(newArr.begin() + i, newAccountMoney);
					break;
				}
			}

		}

	}
	return newArr[0];

}