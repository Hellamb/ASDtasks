#include "Radix2Sorter.h"



void Radix2Sorter::eachDigitSort(vector<long>& arr, int n, int dig)
{
    vector<long> output(n); 
    int i;
    vector<long> counter(10, 0);

   
    for (i = 0; i < n; i++)
        counter[(arr[i] / dig) % 10]++;

    for (i = 1; i < 10; i++)
        counter[i] += counter[i - 1];
 
    for (i = n - 1; i >= 0; i--) {
        output[counter[(arr[i] / dig) % 10] - 1] = arr[i];
        counter[(arr[i] / dig) % 10]--;
    }
 
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}


vector<long> Radix2Sorter::sort(vector<long>& arr)
{ 
    vector<long> ans = arr;
    int m = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > m)
            m = arr[i];
    }

    for (int dig = 1; m / dig > 0; dig *= 10)
        eachDigitSort(ans, arr.size(), dig);
    return ans;
}