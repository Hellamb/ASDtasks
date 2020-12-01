#pragma once
#include <vector>

using namespace std;

class HeapSorter
{
public:
    vector<long> heapify(vector<long>& arr, int n, int i)
    {
        int largest = i;

        int l = 2 * i + 1; 
        int r = 2 * i + 2; 


        if (l < n && arr[l] > arr[largest])
            largest = l;

        if (r < n && arr[r] > arr[largest])
            largest = r;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
        return arr;
    }


    vector<long> sort(vector<long>& arr)
    {
        int n = arr.size();
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(arr, n, i);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
        return arr;
    }

};

