#include "QuickSorter.h"

vector<long> QuickSorter::sort(vector<long>& arr)
{
    int arrSize = arr.size();

    if (arrSize <= 1)
    {
        return arr;
    }
    long middleNum = arr[arrSize / 2];
    vector<long> minArr;
    vector<long> midArr;
    vector<long> maxArr;

    for (long num : arr)
    {
        if (num < middleNum)
        {
            minArr.push_back(num);
        }
        else if (num == middleNum)
        {
            midArr.push_back(num);
        }
        else
        {
            maxArr.push_back(num);
        }
    }
    minArr = sort(minArr);
    maxArr = sort(maxArr);

    minArr.insert(minArr.end(), midArr.begin(), midArr.end());
    minArr.insert(minArr.end(), maxArr.begin(), maxArr.end());
    return minArr;
}
