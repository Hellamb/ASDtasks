#include "StringTask2.h"

char StringTask2::task2(string str1, string str2)
{
	vector<char> ans;
	for (int i = 0; i < str1.length(); i++)
	{
		for (int j = 0; j < str2.length(); j++)
		{
			if (str1[i] == str2[j]) return str1[i];
		}
	}

}

string StringTask2::task1(string str1, string str2)
{
	string biggestString;
	string currentString;
	int str1Size = str1.length();
	int str2Size = str2.length();

	for (int i = 0; i < str1Size - biggestString.length(); i++)
	{
		for (int j = 0; j < str2Size - biggestString.length(); j++)
		{
			currentString = "";
			int left;
			if (str1Size - i > str2Size - j) left = str2Size - j;
			else left = str1Size - i;
			for (int k = 0; k < left; k++)
			{
				if (str1[i + k] == str2[j + k])
				{
					currentString += str1[i + k];
				}
				else break;
			}
			if (currentString.length() > biggestString.length())
			{
				biggestString = currentString;
			}

		}
	}
	return biggestString;
}
