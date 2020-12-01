#include "HeapSorter.h"

long* HeapSorter::sort(long arr[], long n)
{
    long* newArr = new long[n];
    copy(arr, arr + n, newArr);
    
    for (int i = n / 2 - 1; i >= 0; i--)
    { 
        sort_help(newArr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(newArr[0], newArr[i]);
        sort_help(newArr, i, 0);
    }


	return newArr;
}
void HeapSorter::sort_help(long arr[], long n, long i)
{
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 


    if (l < n && arr[l] > arr[largest])
        largest = l;


    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);

        sort_help(arr, n, largest);
    }
}