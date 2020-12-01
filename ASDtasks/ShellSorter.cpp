#include "ShellSorter.h"

vector<long> ShellSorter::sort(vector<long>& arr)
{
    long size = arr.size();
    for (int step = size / 2; step > 0; step /= 2)
    {
        for (int i = step; i < size; i++)
        {
            for (int j = i - step; j >= 0 && arr[j] > arr[j + step]; j -= step)
            {
                int tmp = arr[j];
                arr[j] = arr[j + step];
                arr[j + step] = tmp;
            }
        }
    }
    return arr;
}