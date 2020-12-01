#include "ShellSorter.h"

vector<long> ShellSorter::sort(vector<long>& arr)
{
    long size = arr.size();
    vector<long> ans = arr;
    for (int step = size / 2; step > 0; step /= 2)
    {
        for (int i = step; i < size; i++)
        {
            for (int j = i - step; j >= 0 && ans[j] > ans[j + step]; j -= step)
            {
                swap(ans[j], ans[j + step]);
            }
        }
    }
    return ans;
}